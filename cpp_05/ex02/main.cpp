/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:03:20 by hbelhadj          #+#    #+#             */
/*   Updated: 2024/10/14 22:24:16 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"

int main()
{
    bool CatchOrNot = false;
    // //----------------------------------------------------Test 01----------------------------------------------------//
    {
        std::cout << "-------------------------Test 01 : Can sign all the forms-------------------------" << std::endl;
        Bureaucrat  bureau("Bureau", 5);
        PresidentialPardonForm pres("pres");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm robot("robot");

                                                        /*   Sign forms   */
        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the presidentialPardonForm" << RESET_TEXT << std::endl;
            pres.beSigned(bureau);
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the ShrubberyCreationForm" << RESET_TEXT << std::endl;
            shrub.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the RobotomyRequestForm" << RESET_TEXT << std::endl;
            robot.beSigned(bureau);        
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

                                                    /*   Applicate forms   */
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(pres);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(shrub);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(robot);
    }
    
    
    // ----------------------------------------------------Test 02----------------------------------------------------//
    {
        std::cout << "\n\n--Test 02 : Can sign only ShrubberyCreationForm and RobotomyRequestForm forms--" << std::endl;
        Bureaucrat  bureau("Bureau", 50);

        PresidentialPardonForm pres("pres");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm robot("robot");

                                                        /*   Sign forms   */
        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the presidentialPardonForm" << RESET_TEXT << std::endl;
            pres.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the ShrubberyCreationForm" << RESET_TEXT << std::endl;
            shrub.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the RobotomyRequestForm" << RESET_TEXT << std::endl;
            robot.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;
        std::cout<<"cucu"<<std::endl;
                                                    /*   Applicate forms   */
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(pres);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(shrub);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(robot);
    }
    
    
    //----------------------------------------------------Test 03----------------------------------------------------//
    {
        std::cout << "\n\n------------Test 03 : Can sign only the ShrubberyCreationForm form------------" << std::endl;
        Bureaucrat  bureau("Bureau", 130);
        PresidentialPardonForm pres("pres");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm robot("robot");

                                                        /*   Sign forms   */
        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the presidentialPardonForm" << RESET_TEXT << std::endl;
          pres.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the ShrubberyCreationForm" << RESET_TEXT << std::endl;
            shrub.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;

        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the RobotomyRequestForm" << RESET_TEXT << std::endl;
            robot.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

                                                    /*   Applicate forms   */
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(pres);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(shrub);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(robot);
    }
    

    //----------------------------------------------------Test 04----------------------------------------------------//
    {
        std::cout << "\n\n-------------------------Test 04 : Can't sign any form-------------------------" << std::endl;
        Bureaucrat  bureau("Bureau", 147);
        PresidentialPardonForm pres("pres");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm robot("robot");

                                                        /*   Sign forms   */
        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the presidentialPardonForm" << RESET_TEXT << std::endl;
            pres.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the ShrubberyCreationForm" << RESET_TEXT << std::endl;
            shrub.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

        try
        {
            std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the RobotomyRequestForm" << RESET_TEXT << std::endl;
            robot.beSigned(bureau);
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
            CatchOrNot = true;
        }
        if (!CatchOrNot)
            std::cout << "That Form has been signed successfully by the Bureaucrat\n";
        CatchOrNot = false;

                                                    /*   Applicate forms   */
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(pres);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(shrub);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
        bureau.FormExecute(robot);
    }
}
