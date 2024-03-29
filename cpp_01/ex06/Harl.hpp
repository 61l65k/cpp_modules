/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:08:56 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/25 13:44:15 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_H
# define HARL_CLASS_H

#include <iostream>

class Harl {
    public:
        Harl(void);
        ~Harl(void);
        void complain( std::string level );
        int getIndex( std::string level ) const;
        void set_start_index( std::string level);
        void complain_all( void );
    private:
        static std::string const _complains[4];
        int _start_level;
        int _printed;
        
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif
