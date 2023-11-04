#include <Precomp.h>
#include <HDR_IP/System/CoreSystem/Layer.h>

namespace HDR_IP
{
	Layer::Layer(const std::string& debugName) : m_DebugName(debugName) {}
	Layer::~Layer() {}
}