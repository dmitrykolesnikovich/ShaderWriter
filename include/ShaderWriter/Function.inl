/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	template< typename Param
		, typename ... Params >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, bool isEnabled
		, Param const & current
		, Params const & ... params );

	inline void getFunctionCallParamsRec( expr::ExprList & args
		, bool isEnabled )
	{
	}

	template< typename Param >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, bool isEnabled
		, Param const & last )
	{
		isEnabled = isEnabled && isOptionalEnabled( last );
		args.emplace_back( makeExpr( last ) );
	}

	template< typename Param
		, typename ... Params >
	inline void getFunctionCallParamsRec( expr::ExprList & args
		, bool isEnabled
		, Param const & current
		, Params const & ... params )
	{
		isEnabled = isEnabled && isOptionalEnabled( current );
		args.emplace_back( makeExpr( current ) );
		getFunctionCallParamsRec( args, isEnabled, params... );
	}

	namespace details
	{
		template< typename ReturnT >
		struct FunctionCallGetter
		{
			template< typename ... ParamsT >
			static ReturnT submit( std::string const & name
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( args, isEnabled, params... );
				return ReturnT{ findShader( params... )
					, sdw::makeFnCall( type::makeType( typeEnum< ReturnT > )
						, sdw::makeIdent( var::makeFunction( name ) )
						, std::move( args ) ) };
			}
		};

		template< typename ReturnT >
		struct FunctionCallGetter< Optional< ReturnT > >
		{
			template< typename ... ParamsT >
			static Optional< ReturnT > submit( std::string const & name
				, ParamsT const & ... params )
			{
				expr::ExprList args;
				bool isEnabled = true;
				getFunctionCallParamsRec( args, isEnabled, params... );
				return Optional< ReturnT >{ findShader( params... )
					, sdw::makeFnCall( type::makeType( typeEnum< ReturnT > )
						, sdw::makeIdent( var::makeFunction( name ) )
						, std::move( args ) )
					, isEnabled };
			}
		};
	}
	
	template< typename ReturnT
		, typename ... ParamsT >
	inline ReturnT getFunctionCall( std::string const & name
		, ParamsT const & ... params )
	{
		return details::FunctionCallGetter< ReturnT >::submit( name, params... );
	}

	template< typename ReturnT
		, typename ... ParamsT >
	inline Optional< ReturnT > getOptFunctionCall( std::string const & name
		, ParamsT const & ... params )
	{
		return details::FunctionCallGetter< Optional< ReturnT > >::submit( name, params... );
	}

	//***********************************************************************************************

	template< typename ParamT
		, typename ... ParamsT >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, ParamT && current
		, ParamsT && ... params );

	inline void getFunctionHeaderArgsRec( var::VariableList & args )
	{
	}

	template< typename ParamT >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, ParamT && last )
	{
		auto ident = findIdentifier( last.getExpr() );
		assert( ident != nullptr );
		args.emplace_back( ident->getVariable() );
	}

	template< typename ParamT
		, typename ... ParamsT >
	inline void getFunctionHeaderArgsRec( var::VariableList & args
		, ParamT && current
		, ParamsT && ... params )
	{
		auto ident = findIdentifier( current.getExpr() );
		assert( ident != nullptr );
		args.emplace_back( ident->getVariable() );
		getFunctionHeaderArgsRec( args, std::forward< ParamsT >( params )... );
	}

	template< typename ReturnT
		, typename ... ParamsT >
	inline stmt::ContainerPtr getFunctionHeader( std::string const & name
		, ParamsT && ... params )
	{
		var::VariableList args;
		getFunctionHeaderArgsRec( args, std::forward< ParamsT >( params )... );
		return sdw::makeFuncDecl( type::makeType( typeEnum< ReturnT > )
			, name
			, args );
	}

	template<>
	inline stmt::ContainerPtr getFunctionHeader< void >( std::string const & name )
	{
		var::VariableList args;
		return sdw::makeFuncDecl( type::getVoid()
			, name
			, args );
	}

	//***********************************************************************************************

	template< typename ReturnT
		, typename ... ParamsT >
	Function< ReturnT, ParamsT... >::Function( Shader * shader
		, std::string const & name )
		: m_shader{ shader }
		, m_name{ name }
	{
	}

	template< typename ReturnT
		, typename ... ParamsT >
		ReturnT Function< ReturnT, ParamsT... >::operator()( ParamsT && ... params )const
	{
		assert( !m_name.empty() );
		return getFunctionCall< ReturnT >( m_name
				, std::forward< ParamsT >( params )... );
	}

	//***********************************************************************************************
}
