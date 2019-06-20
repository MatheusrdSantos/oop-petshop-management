#include "../../include/exceptions/InvalidBloodType.h"

InvalidBloodType::InvalidBloodType(std::string value): invalid_argument(m_default_message + value) {

}