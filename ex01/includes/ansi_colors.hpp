/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi_colors.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:10:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/02 14:57:24 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_COLORS_HPP
# define ANSI_COLORS_HPP

/* Basic attributes */
# define C_RESET    "\033[0m"
# define C_BOLD     "\033[1m"
# define C_DIM      "\033[2m"

/* Standard colors */
# define C_BLACK    "\033[30m"
# define C_RED      "\033[31m"
# define C_GREEN    "\033[32m"
# define C_YELLOW   "\033[33m"
# define C_BLUE     "\033[34m"
# define C_MAGENTA  "\033[35m"
# define C_CYAN     "\033[36m"
# define C_WHITE    "\033[37m"

/* Bright variants (se servono) */
# define C_BRED     "\033[1;31m"
# define C_BGREEN   "\033[1;32m"
# define C_BYELLOW  "\033[1;33m"
# define C_BBLUE    "\033[1;34m"
# define C_BMAGENTA "\033[1;35m"
# define C_BCYAN    "\033[1;36m"
# define C_BWHITE   "\033[1;37m"

#endif /* ANSI_COLORS_HPP */
