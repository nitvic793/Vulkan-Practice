
cbuffer ExternalData : register(b0)
{
	matrix model;
	matrix view;
	matrix proj;
};

struct VertexInput
{
	float3 Position : POSITION;
	float3 Color	: COLOR;
	float2 UV		: TEXCOORD0;
};

struct PixelInput
{
	float4 Position : SV_POSITION;
	float3 Color	: COLOR;
	float2 UV		: TEXCOORD0;
};


PixelInput main( VertexInput input)
{
	PixelInput output;
	float4x4 worldViewProj = mul(mul(model, view), proj);
	output.Position = mul(float4(input.Position, 1.f), worldViewProj);
	output.UV = input.UV;
	output.Color = input.Color;
	return output;
}