#pragma once

# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t    serialize(t_data *ptr);
		static t_data       *deserialize(uintptr_t raw);
};
