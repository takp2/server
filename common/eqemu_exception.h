#ifndef _EQEMU_EQEMUEXCEPTION_H
#define _EQEMU_EQEMUEXCEPTION_H

#include <exception>
#include <sstream>

namespace EQ {
//! EQEmu Exception Class
/*!
    A custom exception class for things EQEmu throws.
*/
class Exception : public std::exception {
   public:
	//! Detailed Constructor
	/*!
	    \param name The name given for this exception.
	    \param description The description for this exception.
	    \param file The file name for this exception.
	    \param line The line number for this exception.
	*/
	Exception(const char* name, const std::string& description,
	          const char* file, long line);

	//! Copy Constructor
	Exception(const Exception& e);

	//! Move Constructor
#ifdef EQEMU_RVALUE_MOVE
	Exception(const Exception&& e);
#endif

	//! Destructor
	~Exception() throw() {}

	//! Assignment Operator
	void operator=(const Exception& e);

	//! Get Name
	/*!
	    Gets the name of the exception as it was when it was created.
	    These are typically descriptive categories that the exception would fall
	   under.
	*/
	virtual const std::string& name() const { return name_; }

	//! Get Basic Description
	/*!
	    Gets the description of the exception as it was when it was created.
	    This tends to explain the circumstances of why the exception was thrown.
	*/
	virtual const std::string& description() const { return desc_; }

	//! Get Full Description
	/*!
	    Gets a full description for this exception.
	    This is a string containing the name, description, file and line number
	   in a custom format. This string is created the first time the
	   full_description is accessed.
	*/
	virtual const std::string& full_description() const;

	//! Get File Name
	/*!
	    Gets the name of the file this exception was thrown from.
	*/
	virtual const std::string& file() const { return file_; }

	//! Get File Line
	/*!
	    Gets the file line this exception was thrown from.
	*/
	virtual const long& line() const { return line_; }

	//! std::exception overload
	/*!
	    Overload from std::exception
	    Allows it to be caught as a std::exception without casting which is
	   nice, returns the full description.
	*/
	const char* what() const throw() { return full_description().c_str(); }

   protected:
	mutable std::string full_desc_;  //!< Full Exception Description
	long line_;                      //<! File Line
	std::string file_;               //!< File Name
	std::string desc_;               //!< Exception Description
	std::string name_;               //!< Exception name
};
}  // namespace EQ

#ifndef EQ_EXCEPT
#define EQ_EXCEPT(n, d) throw EQ::Exception(n, d, __FILE__, __LINE__)
#endif

#endif
