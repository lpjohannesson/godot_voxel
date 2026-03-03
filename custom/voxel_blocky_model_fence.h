#pragma once
#include "../meshers/blocky/voxel_blocky_model.h"
#include "../meshers/blocky/voxel_blocky_model_mesh.h"
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/classes/mesh.hpp>
#include <godot_cpp/classes/surface_tool.hpp>

namespace zylann::voxel {

class VoxelBlockyModelFence : public VoxelBlockyModel {
	GDCLASS(VoxelBlockyModelFence, VoxelBlockyModel)

public:
	TypedArray<Mesh> meshes;

	inline TypedArray<Mesh> get_meshes() { return meshes; }
	inline void set_meshes(TypedArray<ArrayMesh> new_meshes) { meshes = new_meshes; }

	void bake(blocky::ModelBakingContext &ctx) const override;
	bool is_empty() const override;

	VoxelBlockyModelFence();

protected:
	static void _bind_methods();

private:
	Ref<VoxelBlockyModelMesh> _model;
	Ref<SurfaceTool> _st;
};

} 
