////////////////////////////////
/// usage : 1.	data that identifies a guillotine cut problem and its solution.
/// 
/// note  : 1.	
////////////////////////////////

#ifndef SMART_CK_RECT_PACKING_PROBLEM_H
#define SMART_CK_RECT_PACKING_PROBLEM_H


#include "Config.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "Common.h"
#include "PbReader.h"
#include "RectPacking.pb.h"


namespace ck {

class Problem {
    #pragma region Type
public:
    struct Input : public pb::RectPacking::Input {
        bool load(const String &path) { return pb::load(path, *this); }
    };

    struct Output : public pb::RectPacking::Output {
        bool save(const String &path, pb::Submission &submission) const {
            std::ofstream ofs(path);
            if (!ofs.is_open()) { return false; }

            // TODO[0]: fill the submission information.
            submission.set_author("ck");
            submission.set_algorithm("rand");
            submission.set_cpu("Intel Core i5-7400 3.00GHz");
            submission.set_ram("16G 2400MHz");
            submission.set_language("C++");
            submission.set_compiler("VS2017");
            submission.set_os("Windows 10");
            submission.set_problem("RectPacking");

            ofs << protobufToJson(submission, false) << std::endl << protobufToJson(*this);
            return true;
        }

        //double useRatio = 0;
    };
    #pragma endregion Type

    #pragma region Constant
public:
    enum {
        MaxGateNum = 100,
        MaxBridgeNum = 30,
        MaxFlightNum = 400,

        InvalidId = -1,
    };
    #pragma endregion Constant

    #pragma region Constructor
public:
    #pragma endregion Constructor

    #pragma region Method
public:
    #pragma endregion Method

    #pragma region Field
public:
    #pragma endregion Field
}; // Problem

}


#endif // SMART_CK_RECT_PACKING_PROBLEM_H
