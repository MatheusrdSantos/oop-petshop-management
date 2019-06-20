#include "../../include/exceptions/InvalidSecurityLevel.h"

InvalidSecurityLevel::InvalidSecurityLevel(std::string value): invalid_argument(m_default_message + value) {

}