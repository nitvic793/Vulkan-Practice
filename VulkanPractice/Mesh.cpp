#include "Mesh.h"

#include <tiny_obj_loader.h>

Mesh MeshManager::LoadModel(const char* filename)
{
	Mesh mesh = {};
	mesh.FirstIndex = currentIndicesIndex;
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn, err;

	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &err, filename))
	{
		throw std::runtime_error(err);
	}

	std::unordered_map<Vertex, uint32_t> uniqueVertices = {};

	for (const auto& shape : shapes)
	{
		for (const auto& index : shape.mesh.indices)
		{
			Vertex vertex = {};
			vertex.position =
			{
				attrib.vertices[3 * index.vertex_index + 0],
				attrib.vertices[3 * index.vertex_index + 1],
				attrib.vertices[3 * index.vertex_index + 2]
			};

			vertex.texCoord =
			{
				attrib.texcoords[2 * index.texcoord_index + 0],
				1.f - attrib.texcoords[2 * index.texcoord_index + 1]
			};

			if (attrib.normals.size() > 0)
			{
				vertex.normal =
				{
					attrib.normals[3 * index.normal_index + 0],
					attrib.normals[3 * index.normal_index + 1],
					attrib.normals[3 * index.normal_index + 2]
				};
			}

			vertex.color = { 1.0f, 1.0f, 1.0f };

			if (uniqueVertices.count(vertex) == 0)
			{
				uniqueVertices[vertex] = (uint32_t)vertices.size();
				vertices.push_back(vertex);
				currentVertexIndex++;
			}

			indices.push_back(uniqueVertices[vertex]);
			currentIndicesIndex++;
		}
	}

	mesh.IndexCount = currentIndicesIndex - mesh.FirstIndex;
	meshes.push_back(mesh);
	return mesh;
}

const Vertex* MeshManager::VertexData()
{
	return vertices.data();
}

const size_t MeshManager::VertexCount()
{
	return vertices.size();
}

const uint32_t* MeshManager::IndexData()
{
	return indices.data();
}

const size_t MeshManager::IndexCount()
{
	return indices.size();
}
