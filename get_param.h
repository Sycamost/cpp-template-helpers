#pragma once

namespace template_helpers
{

    template<unsigned int index, unsigned int In, unsigned int... remPack> struct get_param
    {
        static const unsigned int val = get_param<index - 1, remPack...>::val;
    };

    template<unsigned int In, unsigned int...remPack> struct get_param<0, In, remPack...>
    {
        static const unsigned int val = In;
    };

}