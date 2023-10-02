#include "../hpp/child_commands.hpp"

#include <functional>
#include <numeric>


double AddCommand :: execute(Op_Val_Pair_List& args) {
    double result =0;
    for(auto p : args){
        result += p.second;
    }
    //return std::accumulate(args.begin().second, args.end().second, 0.0);
    return result;
}

double SubCommand :: execute(Op_Val_Pair_List& args){
    std::vector<double> value_list;
    for(auto p : args){
        value_list.push_back(p.second);
    }
    return std::accumulate(std::next(value_list.begin()), value_list.end(), value_list[0], std::minus<float>());
}

double MulCommand :: execute(Op_Val_Pair_List& args){
    std::vector<double> value_list;
    for(auto p : args){
        value_list.push_back(p.second);
    }
    return std::accumulate(value_list.begin(), value_list.end(), 1.0, std::multiplies<float>());
}

double DivCommand :: execute(Op_Val_Pair_List& args){
    std::vector<double> value_list;
    for(auto p : args){
        value_list.push_back(p.second);
    }
    return std::accumulate(std::next(value_list.begin()), value_list.end(), value_list[0], std::divides<float>());
}

double Help :: execute(Op_Val_Pair_List& args){
    return 0;
}

double Exit :: execute(Op_Val_Pair_List& args){
    std::exit(0);
}
