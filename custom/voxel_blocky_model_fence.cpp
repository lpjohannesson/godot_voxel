#include "voxel_blocky_model_fence.h"

using namespace zylann::voxel;

void append_mesh(Ref<SurfaceTool> st, Ref<ArrayMesh> mesh) {
    for (int i = 0; i < mesh->get_surface_count(); i++) {
        st->append_from(mesh, i, Transform3D());
    }
}

void VoxelBlockyModelFence::bake(blocky::ModelBakingContext &ctx) const {
    Ref<ArrayMesh> mesh1 = Object::cast_to<ArrayMesh>(meshes[0]), mesh2 = Object::cast_to<ArrayMesh>(meshes[1]);

    _st->begin(Mesh::PRIMITIVE_TRIANGLES);
    append_mesh(_st, mesh1);
    append_mesh(_st, mesh2);

    _model->set_mesh(_st->commit());
    _model->bake(ctx);
}

bool VoxelBlockyModelFence::is_empty() const {
    return false;
}

VoxelBlockyModelFence::VoxelBlockyModelFence() {
    _model.instantiate();
    _st.instantiate();
}

void VoxelBlockyModelFence::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_meshes"), &VoxelBlockyModelFence::get_meshes);
    ClassDB::bind_method(D_METHOD("set_meshes", "meshes"), &VoxelBlockyModelFence::set_meshes);

    ADD_PROPERTY(
        PropertyInfo(Variant::ARRAY, "meshes", PROPERTY_HINT_ARRAY_TYPE, "ArrayMesh"),
        "set_meshes", "get_meshes");
}