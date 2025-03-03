/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvBlock_H___
#define ___SDW_SpirvBlock_H___
#pragma once

#include "SpirVInstruction.hpp"

namespace spirv
{
	struct VariableInfo
	{
		explicit VariableInfo( DebugId pid = DebugId{}
			, bool pisAlias = false
			, bool pisParam = false
			, bool pisOutParam = false )
			: id{ std::move( pid ) }
			, isAlias{ pisAlias }
			, isParam{ pisParam }
			, isOutParam{ pisOutParam }
		{
		}

		bool needsStoreOnPromote()const;

		DebugId const * operator->()const
		{
			return &id;
		}

		DebugId id;
		bool isAlias;
		bool isParam;
		bool isOutParam;
		bool lvalue{ false };
		bool rvalue{ false };
	};

	struct Block
	{
		Block( Block const & rhs ) = delete;
		Block & operator=( Block const & rhs ) = delete;
		SDWSPIRV_API Block( Block && rhs )noexcept;
		SDWSPIRV_API Block & operator=( Block && rhs )noexcept;
		SDWSPIRV_API ~Block()noexcept = default;

		SDWSPIRV_API explicit Block( ast::ShaderAllocatorBlock * alloc
			, spv::Id plabel = {} );

		SDWSPIRV_API static Block deserialize( ast::ShaderAllocatorBlock * alloc
			, InstructionPtr firstInstruction
			, InstructionList::iterator & buffer
			, InstructionList::iterator const & end );

		// Serialisable.
		spv::Id label{};
		InstructionList instructions;
		InstructionPtr blockEnd{};
		// Used during construction.
		ast::UnorderedMap< DebugIdList, DebugId, DebugIdListHasher > accessChains;
		ast::UnorderedMap< DebugIdList, DebugId, DebugIdListHasher > vectorShuffles;
		bool isInterrupted{};
	};
}

#endif
