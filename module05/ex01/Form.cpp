/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:35:33 by aaitoual          #+#    #+#             */
/*   Updated: 2022/09/18 19:56:50 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

//Default formula for the class***************************************

Form::Form(std::string name_, int grade_req_signe_, int grade_req_execute_) : name(name_), grade_req_execute(grade_req_execute_)
{
	std::cout << "Default constractor called for Form class\n";
	if (grade_req_signe_ > 150 || grade_req_execute_ > 150)
		throw GradeTooLowException;
	if (grade_req_signe_ < 1 || grade_req_execute_ < 1)
		throw GradeTooHighException;
	grade_req_signe = grade_req_signe_;
	signed_ = false;
}

Form::Form(const Form& copy) : name(copy.name), grade_req_execute(copy.grade_req_execute)
{
	std::cout << "Copy constructor called for Form class\n";
	*this = copy;
}

Form& Form::operator = (const Form& copy)
{
	std::cout << "Copy assinement operator called for class Form\n";
	signed_ = copy.signed_;
	grade_req_signe = copy.grade_req_signe;
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called for Form class\n";
}

//getters***************************************************************

std::string Form::getName(void) const
{
	return name;
}

int Form::getGrade_req_execute(void) const
{
	return grade_req_execute;
}

int Form::getGrade_req_signe(void) const
{
	return grade_req_signe;
}

bool Form::getSigne(void) const
{
	return signed_;
}

//operator overload for ostream*****************************************

std::ostream& operator << (std::ostream &os, const Form& arg)
{
	std::string tmp;

	tmp = arg.getName();
	tmp.append(", need at least ");
	tmp.append(std::to_string(arg.getGrade_req_execute()));
	tmp.append(" as a grade to be executed and at least ");
	tmp.append(std::to_string(arg.getGrade_req_signe()));
	tmp.append(" as a grade to be signed and the Form is");
	if (arg.getSigne())
		tmp.append(" signed now\n");
	else
		tmp.append(" not signed now\n");
	os << tmp;
	return os;
}