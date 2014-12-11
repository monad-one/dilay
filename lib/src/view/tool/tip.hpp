#ifndef DILAY_VIEW_TOOL_TIP
#define DILAY_VIEW_TOOL_TIP

#include "macro.hpp"

class QString;

class ViewToolTip {
  public:
    DECLARE_BIG4COPY (ViewToolTip)

    enum class Button   { None, Left, Middle, Right };
    enum class Modifier { None, Ctrl, Shift, Alt };

    QString toString () const;

    void add (Button, Modifier, const QString&);
    void add (Button, const QString&);

  private:
    IMPLEMENTATION
};

#endif
