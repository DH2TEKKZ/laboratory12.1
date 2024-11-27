#include "pch.h"
#include "CppUnitTest.h"
#include "../laboratory12.1/lab12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest121
{
	TEST_CLASS(UnitTest121)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
            char* inputFile = "test_input.bin";
            char* outputFile = "test_output.bin";

            {
                std::ofstream input(inputFile, std::ios::binary);
                std::string inputData = "geometria";  
                for (char c : inputData) {
                    input.write(&c, sizeof(c));
                }
                input.close();
            }

            ProcessBIN1(inputFile, outputFile);

            std::ifstream output(outputFile, std::ios::binary);
            std::string result;
            char c;
            while (output.read(&c, sizeof(c))) {
                result.push_back(c); 
            }
            output.close();

            Assert::AreEqual(result, std::string("ia")); 
		}
	};
}
