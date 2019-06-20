#include "../../include/exceptions/NonIntegerArgument.h"

NonIntegerArgument::NonIntegerArgument(std::string value): invalid_argument(m_default_message + value) {

}