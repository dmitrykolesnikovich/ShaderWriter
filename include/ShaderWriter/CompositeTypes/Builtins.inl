/*
See LICENSE file in root folder
*/
#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Expr/ExprStreamAppend.hpp>
#include <ShaderAST/Expr/MakeIntrinsic.hpp>

namespace sdw
{
#pragma region I/O
	/**
	*name
	*	I/O.
	*/
	/**@{*/
	template< ast::var::Flag FlagT >
	VoidT< FlagT >::VoidT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::var::Flag FlagT >
	ast::type::TypePtr VoidT< FlagT >::makeType( ast::type::TypesCache & cache )
	{
		return Void::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	InputT< DataT >::InputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	InputT< DataT >::InputT( ShaderWriter & writer )
		: InputT{ writer
		, makeExpr( writer
			, getShader( writer ).registerName( "sdwIn"
				, makeType( getTypesCache( writer ) )
				, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr InputT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	OutputT< DataT >::OutputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: DataT< FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	OutputT< DataT >::OutputT( ShaderWriter & writer )
		: OutputT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "sdwIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr OutputT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}
	/**@}*/
#pragma endregion
#pragma region Vertex shader
	/**
	*name
	*	Vertex shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT >
	VertexInT< DataT >::VertexInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, vertexIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_VertexIndex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, instanceIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_InstanceIndex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, drawID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_DrawID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, baseVertex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_BaseVertex"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, baseInstance{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_BaseInstance"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexInT< DataT >::VertexInT( ShaderWriter & writer )
		: VertexInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "vertIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr VertexInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexOutT< DataT >::VertexOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( ""
					, PerVertex::getBaseType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexOutT< DataT >::VertexOutT( ShaderWriter & writer )
		: VertexOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "vertOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eVertexOutput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr VertexOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return DataT< FlagT >::makeType( cache );
	}
	/**@}*/
#pragma endregion
#pragma region Geometry shader
	/**
	*name
	*	Geometry shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	GeomInT< DataT, LayoutT >::GeomInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< InputT< DataT > >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_in"
					, PerVertex::getArrayType( getTypesCache( writer ), getArraySize( LayoutT ) )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
		GeomInT< DataT, LayoutT >::GeomInT( ShaderWriter & writer )
		: GeomInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "geomIn"
					, ast::type::makeGeometryInputType( makeType( getTypesCache( writer ) )
						, LayoutT )
					, FlagT ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryInput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	ast::type::TypePtr GeomInT< DataT, LayoutT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	GeomOutT< DataT >::GeomOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ""
					, PerVertex::getBaseType( getTypesCache( writer ) )
					, var::Flag::eShaderOutput ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	GeomOutT< DataT >::GeomOutT( ShaderWriter & writer
		, type::OutputLayout layout
		, uint32_t count )
		: GeomOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "geomOut"
					, ast::type::makeGeometryOutputType( makeType( getTypesCache( writer ) )
						, layout
						, count ) ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryOutput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	void GeomOutT< DataT >::append()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, sdw::makeSimple( ast::expr::makeStreamAppend( sdw::makeExpr( *this ) ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	void GeomOutT< DataT >::restartStrip()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, sdw::makeSimple( ast::expr::makeEndPrimitive( getTypesCache( writer ) ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr GeomOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
	}
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	PointStreamT< DataT >::PointStreamT( ShaderWriter & writer
		, uint32_t count )
		: GeomOutT< DataT >{ writer, type::OutputLayout::ePointList, count }
	{
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	LineStreamT< DataT >::LineStreamT( ShaderWriter & writer
		, uint32_t count )
		: GeomOutT< DataT >{ writer, type::OutputLayout::eLineStrip, count }
	{
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TriangleStreamT< DataT >::TriangleStreamT( ShaderWriter & writer
		, uint32_t count )
		: GeomOutT< DataT >{ writer, type::OutputLayout::eTriangleStrip, count }
	{
	}
	/**@}*/
#pragma endregion
}
