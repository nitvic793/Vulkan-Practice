
cbuffer ExternalData : register(b0)
{
	column_major matrix model;
	column_major matrix view;
	column_major matrix proj;
};

struct VertexInput
{
	//[[vk::location(0)]] 
	float3 Position : POSITION;
	//[[vk::location(1)]] 
	float3 Color	: COLOR;
	//[[vk::location(2)]] 
	float2 UV		: TEXCOORD0;
};

struct PixelInput
{
	float4 Position : SV_POSITION;
	//[[vk::location(0)]] 
	float3 Color	: COLOR;
	//[[vk::location(1)]] 
	float2 UV		: TEXCOORD0;
};


PixelInput main( VertexInput input)
{
	PixelInput output;
	float4x4 worldViewProj = mul(proj, mul(view, model));
	output.Position = mul(worldViewProj, float4(input.Position, 1.f));
	output.UV = input.UV;
	output.Color = input.Color;
	return output;
}