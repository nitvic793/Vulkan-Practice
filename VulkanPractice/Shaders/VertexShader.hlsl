
cbuffer PerFrame : register(b0) // Binding 0
{
	matrix model;
	matrix view;
	matrix proj;
};

[[vk::binding(2)]]
cbuffer PerObject : register(b1)
{
	matrix world;
}

struct VertexInput
{
	float3 Position : POSITION; // Location 0
	float3 Color	: COLOR; // Location 1
	float3 Normal	: NORMAL; // Location 2
	float2 UV		: TEXCOORD0; // Location 3
};

struct PixelInput
{
	float4 Position : SV_POSITION; // gl_Position
	float3 Color	: COLOR; //Location 0
	float3 Normal	: NORMAL; 
	float2 UV		: TEXCOORD0; //Location 1
}; 

PixelInput main( VertexInput input)
{
	PixelInput output;
	float4x4 worldViewProj = mul(mul(world, view), proj);
	output.Position = mul(float4(input.Position, 1.f), worldViewProj);
	output.UV = input.UV;
	output.Color = input.Color;
	output.Normal = normalize(mul(input.Normal, (float3x3)world));
	return output;
}