#include <fstream>
#include <iostream>

#include <onnx/onnx_pb.h>

int main() {

    std::ifstream file("../models/model.onnx", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Failed to open model\n";
        return 1;
    }

    onnx::ModelProto model;

    if (!model.ParseFromIstream(&file)) {
        std::cerr << "Failed to parse ONNX model\n";
        return 1;
    }

    std::cout << "ONNX model loaded successfully\n";

    const auto& graph = model.graph();
    for (const auto& node : graph.node()) {

    std::cout << "\nOperator: " << node.op_type() << "\n";

    std::cout << "  Inputs:\n";
    for (const auto& input : node.input()) {
        std::cout << "    " << input << "\n";
    }

    std::cout << "  Outputs:\n";
    for (const auto& output : node.output()) {
        std::cout << "    " << output << "\n";
    }

    std::cout << "  Attributes:\n";

    for (const auto& attr : node.attribute()) {

        std::cout << "    " << attr.name();

        if (attr.type() == onnx::AttributeProto::INT) {
            std::cout << " = " << attr.i();
        }
        else if (attr.type() == onnx::AttributeProto::FLOAT) {
            std::cout << " = " << attr.f();
        }

        std::cout << "\n";
    }
}

    return 0;
}