#include "pch.h"
#include "BlenderPyContext.h"
#include "BlenderPyCommon.h"

namespace blender {

extern bContext *g_context;

StructRNA* BlenderPyContext::s_type;
PropertyRNA* BlenderPyContext_blend_data = nullptr;
PropertyRNA* BlenderPyContext_scene = nullptr;
FunctionRNA* BlenderPyContext_evaluated_depsgraph_get = nullptr;
FunctionRNA* BlenderPyContext_depsgraph_update = nullptr;


BlenderPyContext BlenderPyContext::get()
{
    return BlenderPyContext(g_context);
}
Main* BlenderPyContext::data()
{
    return (Main*)get_pointer(m_ptr, BlenderPyContext_blend_data);
}
Scene* BlenderPyContext::scene()
{
    return (Scene*)get_pointer(m_ptr, BlenderPyContext_scene);
}

Depsgraph* BlenderPyContext::evaluated_depsgraph_get()
{
    return call<bContext, Depsgraph*>(m_ptr, BlenderPyContext_evaluated_depsgraph_get);
}

struct HackedDepsGraph {
    char buffer[1240];
};

void BlenderPyContext::UpdateDepsgraph(Depsgraph* depsgraph) {
    HackedDepsGraph* hackedDepsGraph = reinterpret_cast<HackedDepsGraph*>(depsgraph);
    for (int i=308-35; i<308-35+41;++i) {
        hackedDepsGraph->buffer[i] = 1;

    }



    call<Depsgraph, void>(depsgraph, BlenderPyContext_depsgraph_update);
}


} // namespace blender
