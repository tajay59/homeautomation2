  <template>
    <div>
        <VToolbar flat density="compact" color="surface" height="100" >
            <VContainer fluid>
                    <VRow align="center" justify="center">
                        <VCol cols="1" align="left" >
                             
                        </VCol>

                        <VCol cols="10"  align="center"   > 

                             Home Automation System

                        </VCol>
                        <VCol cols="1" align="right">
                            <VBtn size="x-small" :elevation="0"  icon @click="darkmode = !darkmode">                  
                                <VIcon v-if="darkmode" icon="mdi:mdi-weather-night"   ></VIcon>
                                <VIcon v-else  icon="mdi:mdi-white-balance-sunny"  ></VIcon>
                            </VBtn>
                        </VCol>
                    </VRow>
                </VContainer>
            </VToolbar>
      <VNavigationDrawer expand-on-hover rail >
        <VList>
          <VListItem
            :prepend-avatar="`/api/image/profile.jpg`"
            title="IoT Systems"
            subtitle="iot@yanacreations.com"
          ></VListItem>
        </VList>

        <v-divider></v-divider>

        <VList density="compact" nav>
          <VListItem prepend-icon="mdi-home" title="Home" value="Home" :to="{ name: 'Home' }" ></VListItem>
          <VListItem prepend-icon="mdi-walk" title="Virtual Tour" value="Virtual Tour" :to="{ name: 'Virtual' }"></VListItem>
          <VListItem prepend-icon="mdi-monitor-dashboard" title="Dashboard" value="Dashboard" :to="{ name: 'Dashboard' }"></VListItem>
          <VListItem prepend-icon="mdi-chart-line" title="Live" value="Live" :to="{ name: 'Live' }" ></VListItem>      
          <VListItem prepend-icon="mdi-chart-scatter-plot" title="Analysis" value="Analysis" :to="{ name: 'Analysis' }" ></VListItem>       
        </VList>
      </VNavigationDrawer>

        </div>
  </template>

  
  <script setup>
    import { useRoute,useRouter } from "vue-router";
    import { useTheme } from 'vuetify';  
    import { ref ,watch ,onMounted ,onBeforeMount } from 'vue';


  
    // VARIABLES 
    const theme       = useTheme();
    const darkmode    = ref(false); 
    const router      = useRouter();  
    const route       = useRoute();  

    // WATCHERS
    watch(darkmode,  (mode) => {
    theme.global.name.value = mode ?  'darkMode' : 'lightMode';
    localStorage.setItem("theme",mode ? 'darkMode' : 'lightMode');  
    });


    // FUNCTIONS
    onMounted(()=>{
 

    });

    onBeforeMount(()=>{
        // SAVE THEME TO LOCALSTORAGE MAKING IT PERSIST BROWSER REFRESH

        if(localStorage.getItem("theme") != null){
            theme.global.name.value = localStorage.getItem("theme");
            darkmode.value = theme.global.current.value.dark;
        }
        else{
            localStorage.setItem("theme",theme.global.current.value.dark ? 'darkMode' : 'lightMode');
            darkmode.value = theme.global.current.value.dark;    
        }  
    });

 
  </script>

  <style>
    .route {
        text-decoration: none;
        margin-left: 8px;
        margin-right: 8px; 
    }
  </style>
  