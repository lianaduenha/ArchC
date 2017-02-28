#ifndef TLM_PAYLOAD_EXT
#define TLM_PAYLOAD_EXT

#include <tlm.h>

class ac_payload_extension : public tlm::tlm_extension<ac_payload_extension>
	{
		public:
			ac_payload_extension(){
				numberCache = 0;	
				address = 0;
				cacheIndex=0;
				validation = false;
				nWay = 0;
				index_size = 0;
			}
			~ac_payload_extension() {
			}
						
			int getnumberCache () { return numberCache; }
			uint32_t getAddress () { return address; }
			int getCacheIndex(){return cacheIndex;}
			bool getValidation(){return validation;}
			int getNWay () { return nWay;}
			int getIndex_size () { return index_size; }
			
			void setRule(int a){rule =  a; }
			int getRule(){return rule; }
			
			void setNumberCache (int a) { numberCache = a; }
			void setAddress (uint32_t b) { address = b; }
			void setCacheIndex (int index){cacheIndex= index;}
			void setValidation (bool validate){validation = validate;}
			void setNWay (int n) { nWay = n; }
			void setIndex_size (int index) { index_size = index; }
			
			virtual tlm_extension_base* clone() const {
			
				ac_payload_extension *ext = new ac_payload_extension();
				ext->numberCache = numberCache;
				ext->cacheIndex = cacheIndex; 
				ext->address = address; 
				ext->rule = rule;
				ext->validation = validation;
				ext->nWay = nWay;
				ext->index_size = index_size;
				return ext;

			}
			virtual void copy_from(tlm_extension_base const &ext1) {  

				tlm_extension_base* ext2 = ext1.clone ();
				ac_payload_extension *new_ext = reinterpret_cast<ac_payload_extension*> (ext2);

				this->numberCache = new_ext->numberCache;
				this->cacheIndex = new_ext->cacheIndex; 
				this->address = new_ext->address; 
				this->rule = new_ext->rule;
				this->validation = new_ext->validation;
				this->nWay = new_ext->nWay;
				this->index_size = new_ext->index_size;

				// is this delete necessary?
				delete new_ext;
					
			} 
			
		private: 
			int numberCache;
			uint32_t address;
			int cacheIndex;
			int rule; //1 representa read, 2 representa write
			bool validation;
			int nWay;
			int index_size;
	};



#endif