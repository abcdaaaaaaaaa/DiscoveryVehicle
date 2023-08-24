        const screenWidth = window.innerWidth / 2;
        const screenHeight = window.innerHeight;
        
        const LeftrectanglePosition = Math.round(Angle0/Average * screenWidth) - 105 + "px";
        document.documentElement.style.setProperty('--LeftrectanglePosition', LeftrectanglePosition);

        const LeftrectanglePosition30 = Math.round(Angle30/Average * screenWidth) + 105  + "px";
        document.documentElement.style.setProperty('--LeftrectanglePosition30', LeftrectanglePosition30);     
        
        const ForwardrectanglePosition60 = Math.round(Angle60/Average * screenHeight) - 60 + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition60', ForwardrectanglePosition60);
        
        const ForwardrectanglePosition = Math.round(Angle90/Average * screenHeight) - 60  + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition', ForwardrectanglePosition);
        
        const ForwardrectanglePosition120 = Math.round(Angle120/Average * screenHeight) - 60 + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition120', ForwardrectanglePosition120);
        
        const RightrectanglePosition30 = Math.round(Angle150/Average * screenWidth) + 105  + "px";
        document.documentElement.style.setProperty('--RightrectanglePosition30', RightrectanglePosition30);
        
        const RightrectanglePosition = Math.round(Angle180/Average * screenWidth) - 105 + "px";
        document.documentElement.style.setProperty('--RightrectanglePosition', RightrectanglePosition);
        
        const angle = 30;
        const Angle_30 = Math.round(screenHeight / 3 * Math.tan(angle * (Math.PI / 180)) + screenHeight / 3);

        const Blue30 = Math.round(Angle_30 * Angle30/Average) + "px";
        document.documentElement.style.setProperty('--Blue30', Blue30);
        
        const Blue60 = Math.round(Angle_30 * Angle60/Average - (screenHeight / 3)) + "px";
        document.documentElement.style.setProperty('--Blue60', Blue60);
        
        const Blue120 = Math.round(Angle_30 * Angle120/Average - (screenHeight / 3)) + "px";
        document.documentElement.style.setProperty('--Blue120', Blue120);
        
        const Blue150 = Math.round(Angle_30 * Angle150/Average) + "px";
        document.documentElement.style.setProperty('--Blue150', Blue150);
        
        document.documentElement.style.setProperty('--rgb0', rgb0);
        document.documentElement.style.setProperty('--rgb30', rgb30);
        document.documentElement.style.setProperty('--rgb60', rgb60);
        document.documentElement.style.setProperty('--rgb90', rgb90);
        document.documentElement.style.setProperty('--rgb120', rgb120);
        document.documentElement.style.setProperty('--rgb150', rgb150);
        document.documentElement.style.setProperty('--rgb180', rgb180);
        
document.getElementById("pageTitle").textContent = "2D Lidar - Average: " + Average;
