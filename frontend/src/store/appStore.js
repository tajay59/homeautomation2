import {defineStore} from 'pinia'
import {ref} from 'vue'


export const useAppStore =  defineStore('app', ()=>{

    /*  
    The composition API way of defining a Pinia store
    ref() s become state properties
    computed() s become getters
    function() s become actions  
    */ 

    // STATES 
  


    // ACTIONS
 
    
 
	
    const getData = async (start,end)=>{
        // FETCH REQUEST WILL TIMEOUT AFTER 20 SECONDS
        const controller = new AbortController();
        const signal = controller.signal;
        const id = setTimeout(()=>{controller.abort()},60000);
        const URL = `/api/data/${start}/${end}`;
        try {
            const response = await fetch(URL,{ method: 'GET', signal: signal });
            if (response.ok){
                const data = await response.json();
                let keys = Object.keys(data);
                if(keys.includes("status")){
                    if(data["status"] == "found" ){
                        // console.log(data["data"] )
                        return data["data"];
                    }
                    if(data["status"] == "failed" ){
                        console.log("No data returned");
                    }
                }
            }
            else{
            const data = await response.text();
            console.log(data);
            }
        }
        catch(err){
            console.error('getData error: ', err.message);
        }
        return []
        }
          

    return { 
    // EXPORTS	
    getData
        
       }
},{ persist: true  });