#include <json/json.h>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>


int main() {
    const std::string rawJson = R"({"0":"http://static.wkanx.com/w002/M00/04/DA/CgIXlV4lZlaAAtjmAAAhhi_zdh875.jpeg?t=3f69d0f1fbe295cb6edd163e4d0743c5&w=228&h=150","1":"http://static.wkanx.com/w002/M00/04/DA/CgIXgV4lZpOAZvePAAAlonjUBq065.jpeg?t=175760176322cbd94799e537cd2c490c&w=228&h=150","2":"http://static.wkanx.com/w002/M00/04/DA/CgIXGF4lZp6AJS1LAAAT2OtRTB420.jpeg?t=0d2d6761c54a68d0b76630832e66aa8f&w=228&h=150"})";
    const auto rawJsonLength = static_cast<int>(rawJson.length());
    std::string err;
    Json::Value root;

    Json::CharReaderBuilder builder;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(rawJson.c_str(), rawJson.c_str()+rawJsonLength, &root, &err)) {
        std::cout << "error: " << err << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> images;
    for (auto& item : root) {
        images.push_back(item.asString());
    }

    std::cout << "len: " << images.size() << std::endl;

    for (auto& image : images) {
        std::cout << "image: " << image << std::endl;
    }
    return EXIT_SUCCESS;
}
