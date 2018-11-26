/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtConstantBufferDecl_H___
#define ___AST_StmtConstantBufferDecl_H___
#pragma once

#include "StmtCompound.hpp"
#include "StmtVariableDecl.hpp"

#include "ASTGenerator/Type/TypeStruct.hpp"

namespace ast::stmt
{
	class ConstantBufferDecl
		: public Compound
	{
	public:
		ConstantBufferDecl( std::string name
			, type::MemoryLayout layout
			, uint32_t bindingPoint
			, uint32_t bindingSet );
		void add( VariableDeclPtr decl );

		void accept( VisitorPtr vis )override;

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline type::MemoryLayout getMemoryLayout()const
		{
			return m_layout;
		}

		inline uint32_t getBindingPoint()const
		{
			return m_bindingPoint;
		}

		inline uint32_t getDescriptorSet()const
		{
			return m_bindingSet;
		}

	private:
		using Compound::addStmt;

	private:
		std::string m_name;
		type::MemoryLayout m_layout;
		uint32_t m_bindingPoint;
		uint32_t m_bindingSet;
	};
	using ConstantBufferDeclPtr = std::unique_ptr< ConstantBufferDecl >;

	inline ConstantBufferDeclPtr makeConstantBufferDecl( std::string name
		, type::MemoryLayout layout
		, uint32_t bindingPoint
		, uint32_t bindingSet )
	{
		return std::make_unique< ConstantBufferDecl >( std::move( name )
			, layout
			, bindingPoint
			, bindingSet );
	}
}

#endif
