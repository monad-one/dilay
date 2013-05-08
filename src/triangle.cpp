#include <glm/glm.hpp>
#include "triangle.hpp"
#include "macro.hpp"
#include "util.hpp"
#include "ray.hpp"
#include "winged-vertex.hpp"

struct TriangleImpl {
  glm::vec3 vertex1;
  glm::vec3 vertex2;
  glm::vec3 vertex3;

  TriangleImpl () {}

  TriangleImpl (const glm::vec3& v1, const glm::vec3& v2, const glm::vec3& v3) 
    : vertex1 (v1), vertex2 (v2), vertex3 (v3) {}

  TriangleImpl ( const WingedMesh& mesh, LinkedVertex v1
               , LinkedVertex v2, LinkedVertex v3)
    : TriangleImpl (v1->vertex (mesh), v2->vertex (mesh), v3->vertex (mesh)) {}

  glm::vec3 edge1 () const { return this->vertex2 - this->vertex1; }
  glm::vec3 edge2 () const { return this->vertex3 - this->vertex1; }

  glm::vec3 normal () const { 
    return glm::cross (this->edge1 (), this->edge2 ());
  }

  glm::vec3 center () const {
    return (this->vertex1 + this->vertex2 + this->vertex3) / glm::vec3 (3.0f);
  }

  float maxExtent () const {
    glm::vec3 max = glm::max (glm::max (this->vertex1, this->vertex2), this->vertex3);
    glm::vec3 min = glm::min (glm::min (this->vertex1, this->vertex2), this->vertex3);

    glm::vec3 delta = max - min;
    return glm::max (glm::max (delta.x, delta.y), delta.z);
  }

  bool intersectRay (const Ray& ray, glm::vec3& intersection) const {
    glm::vec3 e1 = this->edge1 ();
    glm::vec3 e2 = this->edge2 ();

    glm::vec3 s1  = glm::cross (ray.direction (), e2);
    float divisor = glm::dot (s1, e1);

    if (divisor < Util :: epsilon) 
      return false;

    float     invDivisor = 1.0f / divisor;
    glm::vec3 d          = ray.origin () - this->vertex1;
    glm::vec3 s2         = glm::cross (d,e1);
    float     b1         = glm::dot (d,s1)                 * invDivisor;
    float     b2         = glm::dot (ray.direction (), s2) * invDivisor;
    float     t          = glm::dot (e2, s2)               * invDivisor;

    if (b1 < 0.0f || b2 < 0.0f || b1 + b2 > 1.0f || t < 0.0f) {
      return false;
    }
    else {
      intersection = ray.pointAt (t);
      return true;
    }
  }
};

DELEGATE_BIG4          (Triangle)
DELEGATE3_CONSTRUCTOR  (Triangle, const glm::vec3&, const glm::vec3&, const glm::vec3&)
DELEGATE4_CONSTRUCTOR  (Triangle, const WingedMesh&, LinkedVertex, LinkedVertex, LinkedVertex)

GETTER          (const glm::vec3&  , Triangle, vertex1)
GETTER          (const glm::vec3&  , Triangle, vertex2)
GETTER          (const glm::vec3&  , Triangle, vertex3)

SETTER          (const glm::vec3&  , Triangle, vertex1)
SETTER          (const glm::vec3&  , Triangle, vertex2)
SETTER          (const glm::vec3&  , Triangle, vertex3)

DELEGATE_CONST  (glm::vec3         , Triangle, edge1)
DELEGATE_CONST  (glm::vec3         , Triangle, edge2)
DELEGATE_CONST  (glm::vec3         , Triangle, normal)
DELEGATE_CONST  (glm::vec3         , Triangle, center)
DELEGATE_CONST  (float             , Triangle, maxExtent)
DELEGATE2_CONST (bool              , Triangle, intersectRay, const Ray&, glm::vec3&)
