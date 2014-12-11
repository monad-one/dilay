#ifndef DILAY_VIEW_MAIN_WINDOW
#define DILAY_VIEW_MAIN_WINDOW

#include <QMainWindow>
#include "macro.hpp"

class ViewGlWidget;
class ViewPropertiesWidget;
class ViewToolTip;

class ViewMainWindow : public QMainWindow {
    Q_OBJECT
  public:
    DECLARE_BIG3 (ViewMainWindow)

    ViewGlWidget&         glWidget           ();
    ViewPropertiesWidget& properties         ();
    void                  showMessage        (const QString&);
    void                  showToolTip        (const ViewToolTip&);
    void                  showDefaultToolTip ();
    void                  showNumSelections  (unsigned int);

  private:
    IMPLEMENTATION
};
#endif
