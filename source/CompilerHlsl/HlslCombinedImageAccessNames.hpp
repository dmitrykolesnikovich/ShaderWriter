/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslTextureAccessNames_H___
#define ___AST_HlslTextureAccessNames_H___
#pragma once

#include <ShaderAST/Expr/EnumCombinedImageAccess.hpp>

#pragma warning( push )
#pragma warning( disable: 4365 )
#include <string>
#pragma warning( pop )

namespace hlsl
{
	inline std::string getHlslName( ast::expr::CombinedImageAccess value )
	{
		std::string result;

		switch ( value )
		{
	// Texture Query Functions
		case ast::expr::CombinedImageAccess::eTextureSize1DF:
		case ast::expr::CombinedImageAccess::eTextureSize2DF:
		case ast::expr::CombinedImageAccess::eTextureSize3DF:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeF:
		case ast::expr::CombinedImageAccess::eTextureSize1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureSize2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureSize2DRectF:
		case ast::expr::CombinedImageAccess::eTextureSize2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureSize1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureSize2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureSize1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureSize2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureSizeBufferF:
		case ast::expr::CombinedImageAccess::eTextureSize1DI:
		case ast::expr::CombinedImageAccess::eTextureSize2DI:
		case ast::expr::CombinedImageAccess::eTextureSize3DI:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeI:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureSize2DRectI:
		case ast::expr::CombinedImageAccess::eTextureSize1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureSize2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureSizeBufferI:
		case ast::expr::CombinedImageAccess::eTextureSize1DU:
		case ast::expr::CombinedImageAccess::eTextureSize2DU:
		case ast::expr::CombinedImageAccess::eTextureSize3DU:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeU:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureSize2DRectU:
		case ast::expr::CombinedImageAccess::eTextureSize1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureSize2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureSizeBufferU:
			result = "SDW_textureSize";
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU:
			result = "SDW_textureQueryLod";
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU:
			result = "SDW_textureQueryLevels";
			break;


	// Texel Lookup Functions
		case ast::expr::CombinedImageAccess::eTexture1DF:
		case ast::expr::CombinedImageAccess::eTexture2DF:
		case ast::expr::CombinedImageAccess::eTexture3DF:
		case ast::expr::CombinedImageAccess::eTextureCubeF:
		case ast::expr::CombinedImageAccess::eTexture1DArrayF:
		case ast::expr::CombinedImageAccess::eTexture2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayF:
		case ast::expr::CombinedImageAccess::eTexture2DRectF:
		case ast::expr::CombinedImageAccess::eTexture1DI:
		case ast::expr::CombinedImageAccess::eTexture2DI:
		case ast::expr::CombinedImageAccess::eTexture3DI:
		case ast::expr::CombinedImageAccess::eTextureCubeI:
		case ast::expr::CombinedImageAccess::eTexture1DArrayI:
		case ast::expr::CombinedImageAccess::eTexture2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayI:
		case ast::expr::CombinedImageAccess::eTexture2DRectI:
		case ast::expr::CombinedImageAccess::eTexture1DU:
		case ast::expr::CombinedImageAccess::eTexture2DU:
		case ast::expr::CombinedImageAccess::eTexture3DU:
		case ast::expr::CombinedImageAccess::eTextureCubeU:
		case ast::expr::CombinedImageAccess::eTexture1DArrayU:
		case ast::expr::CombinedImageAccess::eTexture2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayU:
		case ast::expr::CombinedImageAccess::eTexture2DRectU:
		case ast::expr::CombinedImageAccess::eTextureProj1DF2:
		case ast::expr::CombinedImageAccess::eTextureProj1DF4:
		case ast::expr::CombinedImageAccess::eTextureProj2DF3:
		case ast::expr::CombinedImageAccess::eTextureProj2DF4:
		case ast::expr::CombinedImageAccess::eTextureProj3DF:
		case ast::expr::CombinedImageAccess::eTextureProj2DRectF3:
		case ast::expr::CombinedImageAccess::eTextureProj2DRectF4:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2:
		case ast::expr::CombinedImageAccess::eTextureProj1DI4:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3:
		case ast::expr::CombinedImageAccess::eTextureProj2DI4:
		case ast::expr::CombinedImageAccess::eTextureProj3DI:
		case ast::expr::CombinedImageAccess::eTextureProj2DRectI3:
		case ast::expr::CombinedImageAccess::eTextureProj2DRectI4:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2:
		case ast::expr::CombinedImageAccess::eTextureProj1DU4:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3:
		case ast::expr::CombinedImageAccess::eTextureProj2DU4:
		case ast::expr::CombinedImageAccess::eTextureProj3DU:
		case ast::expr::CombinedImageAccess::eTextureProj2DRectU3:
		case ast::expr::CombinedImageAccess::eTextureProj2DRectU4:
			result = "Sample";
			break;

		case ast::expr::CombinedImageAccess::eTexture1DFBias:
		case ast::expr::CombinedImageAccess::eTexture2DFBias:
		case ast::expr::CombinedImageAccess::eTexture3DFBias:
		case ast::expr::CombinedImageAccess::eTextureCubeFBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayFBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayFBias:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayFBias:
		case ast::expr::CombinedImageAccess::eTexture1DIBias:
		case ast::expr::CombinedImageAccess::eTexture2DIBias:
		case ast::expr::CombinedImageAccess::eTexture3DIBias:
		case ast::expr::CombinedImageAccess::eTextureCubeIBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayIBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayIBias:
		case ast::expr::CombinedImageAccess::eTexture1DUBias:
		case ast::expr::CombinedImageAccess::eTexture2DUBias:
		case ast::expr::CombinedImageAccess::eTexture3DUBias:
		case ast::expr::CombinedImageAccess::eTextureCubeUBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayUBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj3DFBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj3DIBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj3DUBias:
			result = "SampleBias";
			break;

		case ast::expr::CombinedImageAccess::eTextureLod1DF:
		case ast::expr::CombinedImageAccess::eTextureLod2DF:
		case ast::expr::CombinedImageAccess::eTextureLod3DF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeF:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureLod1DI:
		case ast::expr::CombinedImageAccess::eTextureLod2DI:
		case ast::expr::CombinedImageAccess::eTextureLod3DI:
		case ast::expr::CombinedImageAccess::eTextureLodCubeI:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureLod1DU:
		case ast::expr::CombinedImageAccess::eTextureLod2DU:
		case ast::expr::CombinedImageAccess::eTextureLod3DU:
		case ast::expr::CombinedImageAccess::eTextureLodCubeU:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjLod3DF:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLod3DI:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLod3DU:
			result = "SampleLevel";
			break;

		case ast::expr::CombinedImageAccess::eTextureOffset1DF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DF:
		case ast::expr::CombinedImageAccess::eTextureOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DRectF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DI:
		case ast::expr::CombinedImageAccess::eTextureOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureOffset2DRectI:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureOffset1DU:
		case ast::expr::CombinedImageAccess::eTextureOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureOffset2DRectU:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectF3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectF4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectI3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectU3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectU4:
			result = "Sample";
			break;

		case ast::expr::CombinedImageAccess::eTextureOffset1DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DIBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DUBias:
			result = "SampleBias";
			break;

		case ast::expr::CombinedImageAccess::eTexelFetch1DF:
		case ast::expr::CombinedImageAccess::eTexelFetch2DF:
		case ast::expr::CombinedImageAccess::eTexelFetch3DF:
		case ast::expr::CombinedImageAccess::eTexelFetch2DRectF:
		case ast::expr::CombinedImageAccess::eTexelFetch1DArrayF:
		case ast::expr::CombinedImageAccess::eTexelFetch2DArrayF:
		case ast::expr::CombinedImageAccess::eTexelFetchBufferF:
		case ast::expr::CombinedImageAccess::eTexelFetch1DI:
		case ast::expr::CombinedImageAccess::eTexelFetch2DI:
		case ast::expr::CombinedImageAccess::eTexelFetch3DI:
		case ast::expr::CombinedImageAccess::eTexelFetch2DRectI:
		case ast::expr::CombinedImageAccess::eTexelFetch1DArrayI:
		case ast::expr::CombinedImageAccess::eTexelFetch2DArrayI:
		case ast::expr::CombinedImageAccess::eTexelFetchBufferI:
		case ast::expr::CombinedImageAccess::eTexelFetch1DU:
		case ast::expr::CombinedImageAccess::eTexelFetch2DU:
		case ast::expr::CombinedImageAccess::eTexelFetch3DU:
		case ast::expr::CombinedImageAccess::eTexelFetch2DRectU:
		case ast::expr::CombinedImageAccess::eTexelFetch1DArrayU:
		case ast::expr::CombinedImageAccess::eTexelFetch2DArrayU:
		case ast::expr::CombinedImageAccess::eTexelFetchBufferU:
			result = "Load";
			break;

		case ast::expr::CombinedImageAccess::eTexelFetchOffset1DF:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DF:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset3DF:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectF:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayF:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset1DI:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DI:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset3DI:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectI:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayI:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset1DU:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DU:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset3DU:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectU:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayU:
		case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayU:
			result = "Load";
			break;

		case ast::expr::CombinedImageAccess::eTextureLodOffset1DF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DU:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureLodOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DU:
			result = "SampleLevel";
			break;

		case ast::expr::CombinedImageAccess::eTextureGrad1DF:
		case ast::expr::CombinedImageAccess::eTextureGrad2DF:
		case ast::expr::CombinedImageAccess::eTextureGrad3DF:
		case ast::expr::CombinedImageAccess::eTextureGradCubeF:
		case ast::expr::CombinedImageAccess::eTextureGrad2DRectF:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGrad2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGradCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureGrad1DI:
		case ast::expr::CombinedImageAccess::eTextureGrad2DI:
		case ast::expr::CombinedImageAccess::eTextureGrad3DI:
		case ast::expr::CombinedImageAccess::eTextureGradCubeI:
		case ast::expr::CombinedImageAccess::eTextureGrad2DRectI:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGrad2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGradCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureGrad1DU:
		case ast::expr::CombinedImageAccess::eTextureGrad2DU:
		case ast::expr::CombinedImageAccess::eTextureGrad3DU:
		case ast::expr::CombinedImageAccess::eTextureGradCubeU:
		case ast::expr::CombinedImageAccess::eTextureGrad2DRectU:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGrad2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGradCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad3DF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectF3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectF4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad3DI:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectI3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectI4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGrad3DU:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectU3:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectU4:
			result = "SampleGrad";
			break;

		case ast::expr::CombinedImageAccess::eTextureGradOffset1DF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectF3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectF4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectI3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectI4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectU3:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectU4:
			result = "SampleGrad";
			break;

		case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
			result = "SampleGrad";
			break;

		case ast::expr::CombinedImageAccess::eTextureGrad2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
			result = "SampleGrad";
			break;

	// Texel Compare Functions
		case ast::expr::CombinedImageAccess::eTexture1DShadowF:
		case ast::expr::CombinedImageAccess::eTexture2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureCubeShadowF:
		case ast::expr::CombinedImageAccess::eTexture1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTexture2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTexture2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTexture1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureCubeShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
			result = "SampleCmp";
			break;

	// Texture Gather Functions
		case ast::expr::CombinedImageAccess::eTextureGather2DF:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureGather2DRectF:
		case ast::expr::CombinedImageAccess::eTextureGather2DI:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeI:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureGather2DRectI:
		case ast::expr::CombinedImageAccess::eTextureGather2DU:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeU:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureGather2DRectU:
			result = "Gather";
			break;

		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectU:
			result = "Gather";
			break;

		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectU:
			result = "Gather";
			break;

	// Texture Gather Compare Functions
		case ast::expr::CombinedImageAccess::eTextureGather2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGather2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectShadowF:
			result = "GatherCmpRed";
			break;

		default:
			throw ast::Exception{ "Unsupported CombinedImageAccess type." };
		}

		return result;
	}
}

#endif
