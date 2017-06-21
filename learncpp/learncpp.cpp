
// learncpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//https://msdn.microsoft.com/en-us/library/te3ecsc8.aspx
//The ref new aggregate keyword allocates an instance of a type that is garbage collected when the object becomes inaccessible, and that returns a handle(^) to the allocated object.
 
//All Runtimes
//Memory for an instance of a type that is allocated by ref new is deallocated automatically.
//A ref new operation throws OutOfMemoryException if it is unable to allocate memory.
//For more information about how memory for native C++ types is allocated and deallocated, see the new and delete operators.

//Windows Runtime
//Use ref new to allocate memory for Windows Runtime objects whose lifetime you want to administer automatically.The object is automatically deallocated when its reference count goes to zero, which occurs after the last copy of the reference has gone out of scope.For more information, see Ref classes and structs.
//Requirements: Compiler option : / ZW

//Common Language Runtime
//Memory for a managed type(reference or value type) is allocated by gcnew, and deallocated by using garbage collection.
//Requirements: Compiler option : / clr



//example 1 
// compile with /clr  
using namespace System;
value class Boxed {
public:
	int i;
};

//example 2
// compile with: /clr  
//notice: set properties: using crl, don't use ZW. otherwise: can't combine C++\CX and C++\CLI
//in property->	c/c++->	code generation: do not use -gm, do not use CTRL1

ref struct Message
{
	System::String^ sender;
	System::String^ receiver;
	System::String^ data;

};


int main()
{

	//example 1:  uses gcnew to create a boxed value type for use like a reference type.
	Boxed^ y = gcnew Boxed;
	y->i = 32;
	Console::WriteLine(y->i);

	//example 2: uses gcnew to allocate a Message object.
	Message^ h_Message = gcnew Message;  

	getchar();
	getchar();
    return 0;
}

