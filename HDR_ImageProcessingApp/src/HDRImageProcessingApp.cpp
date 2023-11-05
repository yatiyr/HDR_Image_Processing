#include <HdrIp.h>

#include <EntryPoint.h>
#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include <RecoverResponseCurve_HW1/RecoverResponseCurve_HW1.h>

namespace HDR_IP
{
    class HdrIpApp : public Application
    {
    public:
        HdrIpApp()
            : Application("Gp App")
        {
            RecoverResponseCurve_HW1* recoverResponseCurve_HW1 = RecoverResponseCurve_HW1::CreateRecoverResponseCurve_HW1();
            PushLayer(recoverResponseCurve_HW1);
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
