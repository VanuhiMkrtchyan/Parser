#ifndef CHILD_COMMANDS
#define CHILD_COMMANDS

#include "command.hpp"
class AddCommand : public Command{
    public:
        double execute(Op_Val_Pair_List& args) override;
        AddCommand(){};
        ~AddCommand(){};
};

class SubCommand : public Command{
    public:
        double execute(Op_Val_Pair_List& args) override;
        SubCommand(){};
        ~SubCommand(){};
};

class MulCommand : public Command{
    public:
        double execute(Op_Val_Pair_List& args) override;
        MulCommand(){};
        ~MulCommand(){};
};

class DivCommand : public Command{
    public:
        double execute(Op_Val_Pair_List& args) override;
        DivCommand(){};
        ~DivCommand(){};
};


class Help : public Command{
	public:
		double execute(Op_Val_Pair_List& args) override;
		Help(){};
		~Help(){};
};

class Exit : public Command{
	public:
		double execute(Op_Val_Pair_List& args) override;
		Exit(){};
		~Exit(){};
};

#endif //CHILD_COMMANDS