#ifndef INTERFACES_H
#define INTERFACES_H

#define interface   struct
#define extends     public
#define implements  virtual public

interface AsSelector
{
    //virtual ~Selectable() = 0;
    virtual const char* get_selector_name() = 0;
};

interface AsUser
{
    virtual const char* get_user_name() = 0;
};

interface AsTool{
    virtual const char* get_tool_name() = 0;
};

interface AsTarget
{
    virtual const char* get_target_name() = 0;
};

#endif // INTERFACES_H
