/* This file is part of Dilay
 * Copyright © 2015,2016 Alexander Bau
 * Use and redistribute under the terms of the GNU General Public License
 */
#include <iostream>
#include <QCoreApplication>
#include "test-bitset.hpp"
#include "test-distance.hpp"
#include "test-intersection.hpp"
#include "test-maybe.hpp"
#include "test-misc.hpp"
#include "test-monotone-deque.hpp"
#include "test-octree.hpp"
#include "test-tree.hpp"

int main () {
  QCoreApplication::setApplicationName ("dilay");

  TestIntersection ::test  ();
  TestMaybe        ::test1 ();
  TestMaybe        ::test2 ();
  TestMaybe        ::test3 ();
  TestOctree       ::test  ();
  TestBitset       ::test  ();
  TestTree         ::test1 ();
  TestTree         ::test2 ();
  TestMisc         ::test  ();
  TestDistance     ::test  ();
  TestMonotoneDeque::test1 ();
  TestMonotoneDeque::test2 ();

  std::cout << "all tests run successfully\n";
  return 0;
}

