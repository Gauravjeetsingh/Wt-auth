#ifndef CUSTOM_AUTH_
#define CUSTOM_AUTH_

#include <Wt/WApplication>
#include <Wt/WText>

#include "auth.h"

using namespace Wt;

class CustomAuth : public WApplication
{
public: CustomAuth(const WEnvironment &env);
};

#endif
