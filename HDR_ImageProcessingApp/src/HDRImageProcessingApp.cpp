#include <HdrIp.h>

#include <EntryPoint.h>
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <Editor/EditorLayer.h>

namespace HDR_IP
{
    class HdrIpApp : public Application
    {
    public:
        HdrIpApp()
            : Application("Gp App")
        {
            EditorLayer* editorLayer = EditorLayer::CreateEditor();
            PushLayer(editorLayer);
        }

        ~HdrIpApp()
        {

        }
    };

    Application* CreateApplication()
    {
        return new HdrIpApp();
    }
}
