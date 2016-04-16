/******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015-2016 Baldur Karlsson
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

#include "spirv_common.h"

#undef min
#undef max

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4481) // nonstandard extension used: override specifier 'override'
#pragma warning(disable: 4510) // default constructor could not be generated
#pragma warning(disable: 4610) // struct '' can never be instantiated - user defined constructor required
#endif

#include "3rdparty/glslang/glslang/Public/ShaderLang.h"

#ifdef _MSC_VER
#pragma warning(pop)
#endif

static bool inited = false;

void InitSPIRVCompiler()
{
	if(!inited)
	{
		glslang::InitializeProcess();
		inited = true;
	}
}

void ShutdownSPIRVCompiler()
{
	if(inited)
	{
		glslang::FinalizeProcess();
	}
}
