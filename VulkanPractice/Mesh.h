#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include "Vertex.h"


struct Mesh
{
	uint32_t IndexCount;
	uint32_t FirstIndex;
};

class MeshManager
{
public:
	Mesh LoadModel(const char* filename);
	const Vertex* VertexData();
	const size_t VertexCount();
	const uint32_t* IndexData();
	const size_t IndexCount();

private:
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
	std::vector<Mesh> meshes;

	uint32_t currentVertexIndex = 0;
	uint32_t currentIndicesIndex = 0;
};