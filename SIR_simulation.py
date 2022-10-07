import SIR_xml_config
import os

if __name__ == "__main__":
    try:
        SIR_xml_config.createXML()
    except:
        print("Something went wrong creating the XML file...")
    
    os.system("argos3 -c SIR_sim.xml")