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
    return 0;
}

double MulCommand :: execute(Op_Val_Pair_List& args){
    return 0;
}

double DivCommand :: execute(Op_Val_Pair_List& args){
    return 0;
}

double Help :: execute(Op_Val_Pair_List& args){
    return 0;
}

double Exit :: execute(Op_Val_Pair_List& args){
    return 0;
}
