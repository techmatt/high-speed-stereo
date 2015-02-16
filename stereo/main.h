
//
// main.h
//
// Standard header for synthesis project
//

#include "mLibInclude.h"

using namespace ml;
using std::vector;
using std::set;
using std::map;
using std::string;
using std::pair;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::to_string;
using std::function;

#include "stereoParams.h"

#include "eventMap.h"
#include "assetRenderer.h"

#include "../stereoAnalysis/stereoFrame.h"

struct AppState;

class VizzerModeInterface
{
public:
    virtual void render() {}
    virtual void renderPBRT(const std::string& path) {}
    virtual void keyDown(UINT key) {}
    virtual void keyPressed(UINT key) {}
    virtual void mouseDown(ml::MouseButtonType button) {}
    virtual void mouseMove() {}
    virtual void mouseWheel(int wheelDelta) {}
    virtual vector< pair<string, RGBColor> > statusText() const
    {
        return vector< pair<string, RGBColor> >();
    }
    virtual string helpText() const
    {
        return string("No help text");
    }
};

#include "modeView2D.h"
#include "modeView3D.h"

#include "appState.h"
#include "vizzer.h"
