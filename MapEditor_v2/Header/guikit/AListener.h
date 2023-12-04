#pragma once
#ifndef ACTION_LISTENER_H_INCLUDED
#define ACTION_LISTENER_H_INCLUDED

#include "guikit/AGuiObject.h"

namespace wl
{
    class AListener {
    public:
        virtual void actionPerformed(wl::AGuiObject& obj) = 0;
    };

} // namespace wl

#endif