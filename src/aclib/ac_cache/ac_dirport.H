/* @file      ac_memport.H
 * @author    Thiago Massariolli Sigrist
 *
 *            The ArchC Team
 *            http://www.archc.org/
 *
 *            Computer Systems Laboratory (LSC)
 *            IC-UNICAMP
 *            http://www.lsc.ic.unicamp.br/
 *
 * @version   1.0
 * @date      Thu Sep 22 11:47:36 2005
 *
 * @brief     Defines a wrapper template class for memory access.
 *
 * @attention Copyright (C) 2002-2006 --- The ArchC Team
 * 
 */

//////////////////////////////////////////////////////////////////////////////

#ifndef _AC_DIRPORT_H_
#define _AC_DIRPORT_H_

//////////////////////////////////////////////////////////////////////////////

// Standard includes
#include <stdint.h>
#include <list>
#include <fstream>

// SystemC includes

// ArchC includes
#include "ac_log.H"
#include "ac_utils.H"
#include "ac_payload_extension.H"
#include "ac_tlm2_port.H"
#include "ac_tlm2_nb_port.H"
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////

// Forward class declarations, needed to compile

//////////////////////////////////////////////////////////////////////////////

#define DIR_NB

/// Template wrapper class for memory access.
class ac_dirport
{

private:

  ac_tlm2_payload* payload;     /* PAYLOAD   */
  ac_payload_extension* payloadExt;
  
  #ifdef DIR_NB
  ac_tlm2_nb_port* storage;
  #else
  ac_tlm2_port* storage;
  #endif
  sc_core::sc_time time_info;
  unsigned int procId;

 protected:

public:

  ///Default constructor
  explicit ac_dirport() : time_info(0,SC_NS){
      
      payload = new ac_tlm2_payload();
      payloadExt = new ac_payload_extension();
 
   
  }

  ///Default constructor with initialization
  #ifdef DIR_NB
  explicit ac_dirport(ac_tlm2_nb_port& stg) : storage(&stg),time_info(0,SC_NS) {
      
      payload = new ac_tlm2_payload();
      payloadExt = new ac_payload_extension();
 
  }
  #else
  explicit ac_dirport(ac_tlm2_port& stg) : storage(&stg),time_info(0,SC_NS) {
      
      payload = new ac_tlm2_payload();
      payloadExt = new ac_payload_extension();
 
  }
  #endif

  virtual ~ac_dirport() { delete payload; }

  void setProcId(unsigned int id)
  {  
      procId = id;  
  }



void read(uint32_t address, int cacheIndex, int nCache)
{
    
    sc_core::sc_time time = sc_core::sc_time(0, SC_NS);
    int rule=1;
    payloadExt->setNumberCache(nCache);
    payloadExt->setAddress(address);
    payloadExt->setCacheIndex(cacheIndex);
    payloadExt->setRule(rule);
  
    payload->set_extension(payloadExt);
    payload->set_command(tlm::TLM_READ_COMMAND);
    payload->set_address((sc_dt::uint64)DIR_ADDRESS);
    payload->set_data_length(sizeof(uint32_t));    

    storage->read(payload,time);
    setTimeInfo(time);
    
    
}

  void write(uint32_t address, int cacheIndex, int nCache)
  {
    
    sc_core::sc_time time = sc_core::sc_time(0, SC_NS);
    bool resposta=false;
    int rule=2;
    payloadExt->setNumberCache(nCache);
    payloadExt->setAddress(address);
    payloadExt->setCacheIndex(cacheIndex);
    payloadExt->setRule(rule);
  
    payload->set_extension(payloadExt);
    payload->set_command(tlm::TLM_READ_COMMAND);
    payload->set_address((sc_dt::uint64)DIR_ADDRESS);
    payload->set_data_length(sizeof(uint32_t));


    storage->write(payload,time);
    setTimeInfo (time);
    
  }
  
  bool check(uint32_t address, int nCache, int cacheIndex)
  {

    
    sc_core::sc_time time = sc_core::sc_time(0, SC_NS);
    bool resposta=false;

    int rule=3;

    payloadExt->setNumberCache(nCache);
    payloadExt->setAddress(address);
    payloadExt->setRule(rule);
    payloadExt->setCacheIndex(cacheIndex);
  
    payload->set_extension(payloadExt);
  
    payload->set_command(tlm::TLM_READ_COMMAND);
    payload->set_address((sc_dt::uint64)DIR_ADDRESS);
  
    payload->set_data_length(sizeof(uint32_t));

    storage->read(payload, time);
    setTimeInfo (time);
    resposta = payloadExt->getValidation();
    return resposta;
  }


  void setTimeInfo(sc_core::sc_time time)
  { 
      time_info = time;
  }

};

#endif
