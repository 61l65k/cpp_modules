/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:08:56 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/25 13:37:41 by apyykone         ###   ########.fr       */
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

    private:
        static std::string const _complains[4];
        
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif