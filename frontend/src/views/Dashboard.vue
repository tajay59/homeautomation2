<template>
    <VContainer fluid class=" mb-10 scrolleffect" align="center"  >
        <VRow class="mt-5"   style="width: 1000px; height: 750px;" justify="center">
            <VCol   style="position: relative;">
                <VCard   width="1000"  height="748" color="surface" :image="`/api/image/floorplan.png`"  flat > </VCard>

                <VSheet rounded="sm"  width="360" :color="livingroomColor" height="360" position="absolute" style="left: 125px; top: 50px; "  >
                    <!-- LIVING ROOM -->                    
                    <VCard subtitle="Livingroom Lighting" color="surfaceVariant" :style="`position: absolute; left: ${(smAndDown)? '50px': '-300px'}; top: ${(smAndDown)? '100px': '0px'};`">
                        <!-- 1. Implement a ColorPicker component -->
                        
                    </VCard>                                        
                </VSheet>

                <VSheet rounded="sm"  width="295" :color="`rgba(0, 0, 0,0.5)`" height="260" position="absolute" style="left: 685px; top: 50px; "  >
                    <!-- MASTER BEDROOM -->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                <VSheet class="d-flex justify-center align-center" width="90" height="90" density="compact" rounded="lg"  >
                                     <!-- 2. Implement a ProgressCircular component -->
                                                                                
                                   
                                </VSheet>
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>

                <VSheet rounded="sm"  width="200" :color="`rgba(0, 0, 0, 0.5)`" height="260" position="absolute" style="left: 485px; top: 50px; "  >
                    <!-- MINI BEDROOM -->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                <!-- 3. Implement a Button component with Icons -->
                                
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>

                
                <VSheet rounded="sm"  width="360" :color="`rgba(0, 0, 0, 0.5)`" height="240" position="absolute" style="left: 125px; top: 410px; "  >
                    <!-- KITCHEN -->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                <!-- 4. Implement a Button component with Icons -->
                                
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>

                <VSheet rounded="sm"  width="160" :color="`rgba(0, 0, 0, 0.5)`" height="240" position="absolute" style="left: 630px; top: 410px; "  >
                    <!-- MINI BATHROOM -->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                <!-- 5. Implement a Button component with Icons -->
                                
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>

                <VSheet rounded="sm"  width="190" :color="`rgba(0, 0, 0, 0.5)`" height="140" position="absolute" style="left: 790px; top: 510px; "  >
                    <!-- LAUNDRY ROOM-->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                <!-- 6. Implement a Button component with Icons -->
                                
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>


                <VSheet rounded="sm"  width="190" :color="`rgba(0, 0, 0, 0.5)`" height="205" position="absolute" style="left: 790px; top: 310px; "  >
                    <!-- MASTER BATHROOM -->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                <!-- 7. Implement a Button component with Icons -->
                                
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>

                <VSheet rounded="sm"  width="300" color="rgba(255, 200, 25, 0)" height="100" position="absolute" style="left: 490px; top: 310px; "  >
                    <!-- HALL -->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                <!-- 8. Implement a Card component with Icons to display sensor data -->
                                
                            </VCol> 
                        </VRow>
                    </VContainer>                    
                </VSheet>

                <VSheet rounded="sm"  width="100" color="rgba(255, 200, 255, 0)" height="100" position="absolute" style="left: 0px; top: 310px; "  >
                    <!-- SIDE DOOR -->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                <!-- 9. Implement a Card components with Icons to display the state(Open or Closed) of the side door -->
                                
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>

                <VSheet rounded="sm"  width="70" color="rgba(255, 200, 255, 0)" height="70" position="absolute" style="left: 500px; top: 690px; "  >
                    <!-- FRONT DOOR -->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                            <!-- 10. Implement a Card components with Icons to display the state(Open or Closed) of the front door -->
                                
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>

                <VSheet rounded="sm"  width="70" color="rgba(255, 200, 255, 0)" height="70" position="absolute" style="left: 510px; top: -40px; "  >
                    <!-- BURGLAR BAR-->
                    <VContainer fluid class=" fill-height" align="center"  >
                        <VRow justify="center">
                            <VCol align="center">
                                 <!-- 11. Implement a Card components with Icons to display the state(Open or Closed) of the Window in room C -->
                               
                            </VCol>
                        </VRow>
                    </VContainer>                    
                </VSheet>
            

            </VCol>
        </VRow>
       
    </VContainer> 
</template>

<script setup>
/** JAVASCRIPT HERE */

// IMPORTS
import { ref,reactive,watch ,onMounted,onBeforeUnmount,computed } from "vue";  
import { useRoute ,useRouter } from "vue-router";
import { useDisplay } from 'vuetify'
 
 
// VARIABLES
const { smAndDown }   = useDisplay();
const router                    = useRouter();
const route                     = useRoute();  





// COMPUTED PROPERTIES



// WATCHERS

 



// FUNCTIONS
onMounted(()=>{
    // THIS FUNCTION IS CALLED AFTER THIS COMPONENT HAS BEEN MOUNTED
   
});


onBeforeUnmount(()=>{
    // THIS FUNCTION IS CALLED RIGHT BEFORE THIS COMPONENT IS UNMOUNTED
   
});




</script>


<style scoped>
/** CSS STYLE HERE */

.scrolleffect{
    overflow-y: scroll;
}

/* Hide scrollbar for Chrome, Safari and Opera */
.scrolleffect::-webkit-scrollbar {
    display: none;
}

/* Hide scrollbar for IE, Edge and Firefox */
.scrolleffect {
  -ms-overflow-style: none;  /* IE and Edge */
  scrollbar-width: none;  /* Firefox */
}

</style>
  