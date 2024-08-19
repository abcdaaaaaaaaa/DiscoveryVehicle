        const screenWidth = window.innerWidth / 2;
        const screenHeight = window.innerHeight / 2;
		const Heightdeviation = screenHeight * Math.sqrt(3) / 3;
		const pixellength = 15; // this is the length of the square (pixel)
		const Npixellength = 15; // It is the deviation pixel caused by two different containers.
		const Fullpixellength = pixellength * 2;
	    const Widthcoefficient = screenWidth / Average;
	    const Heightcoefficient = screenHeight / Average;
		const UnitDistance = screenHeight - pixellength;
		const FullUnitDistance = screenHeight - Fullpixellength;
		
		function square(x) { return Math.pow(x,2); }
        function parabola(x) { return Heightdeviation * (square(x) + x); }
        function tan(x) { return Math.tan(x * (Math.PI / 180)); }
        function sin(x) { return Math.sin(x * (Math.PI / 180)); }

        document.documentElement.style.setProperty('--sin15', sin(15));
        document.documentElement.style.setProperty('--sin30', sin(30));
        document.documentElement.style.setProperty('--sin45', sin(45));
        document.documentElement.style.setProperty('--sin60', sin(60));
        document.documentElement.style.setProperty('--sin75', sin(75));
        document.documentElement.style.setProperty('--sin90', sin(90));
		
        document.documentElement.style.setProperty('--tan45', tan(45));
        document.documentElement.style.setProperty('--tan60', tan(60));
        document.documentElement.style.setProperty('--tan75', tan(75));
        document.documentElement.style.setProperty('--tan90', tan(90));

        document.documentElement.style.setProperty('--UnitDistance', UnitDistance + "px");
		document.documentElement.style.setProperty('--screenWidth', screenWidth / 1024 + "px");
        
        const LeftrectanglePosition = Math.round(Angle0 * Widthcoefficient - Fullpixellength / sin(90) - pixellength) + "px";
        document.documentElement.style.setProperty('--LeftrectanglePosition', LeftrectanglePosition);

        const LeftrectanglePosition15 = Math.round(Angle15 * Widthcoefficient + Fullpixellength / sin(15) + pixellength) + "px";
        document.documentElement.style.setProperty('--LeftrectanglePosition15', LeftrectanglePosition15);   

        const LeftrectanglePosition30 = Math.round(Angle30 * Widthcoefficient + Fullpixellength / sin(30) - pixellength) + "px";
        document.documentElement.style.setProperty('--LeftrectanglePosition30', LeftrectanglePosition30);     
		
        const ForwardrectanglePosition45 = Math.round(Angle45 * Heightcoefficient + FullUnitDistance - Npixellength + Npixellength * square(sin(45))) + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition45', ForwardrectanglePosition45); 
        
        const ForwardrectanglePosition60 = Math.round(Angle60 * Heightcoefficient + FullUnitDistance - Npixellength + (Npixellength - tan(60)) * sin(60)) + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition60', ForwardrectanglePosition60);
		
        const ForwardrectanglePosition75 = Math.round(Angle75 * Heightcoefficient + FullUnitDistance - Npixellength + Npixellength * sin(75)) + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition75', ForwardrectanglePosition75);
		
        const ForwardrectanglePosition135 = Math.round(Angle135 * Heightcoefficient + FullUnitDistance - Npixellength + Npixellength * square(sin(45))) + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition135', ForwardrectanglePosition135); 
        
        const ForwardrectanglePosition = Math.round(Angle90 * Heightcoefficient + FullUnitDistance - Npixellength + Npixellength * sin(90)) + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition', ForwardrectanglePosition);
		
        const ForwardrectanglePosition105 = Math.round(Angle105 * Heightcoefficient + FullUnitDistance - Npixellength + Npixellength * sin(75)) + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition105', ForwardrectanglePosition105);
        
        const ForwardrectanglePosition120 = Math.round(Angle120 * Heightcoefficient + FullUnitDistance - Npixellength + (Npixellength - tan(60)) * sin(60)) + "px";
        document.documentElement.style.setProperty('--ForwardrectanglePosition120', ForwardrectanglePosition120);
        
        const RightrectanglePosition30 = Math.round(Angle150 * Widthcoefficient + Fullpixellength / sin(30) - pixellength) + "px";
        document.documentElement.style.setProperty('--RightrectanglePosition30', RightrectanglePosition30);
		
        const RightrectanglePosition15 = Math.round(Angle165 * Widthcoefficient + Fullpixellength / sin(15) + pixellength) + "px";
        document.documentElement.style.setProperty('--RightrectanglePosition15', RightrectanglePosition15);
        
        const RightrectanglePosition = Math.round(Angle180 * Widthcoefficient - Fullpixellength / sin(90) - pixellength) + "px";
        document.documentElement.style.setProperty('--RightrectanglePosition', RightrectanglePosition);
		

        const Blue15 = Math.round(parabola(tan(15)) * Angle15/Average + UnitDistance + Heightdeviation * tan(15) - Fullpixellength) + "px";
        document.documentElement.style.setProperty('--Blue15', Blue15);

        const Blue30 = Math.round(parabola(tan(30)) * Angle30/Average + UnitDistance) + "px";
        document.documentElement.style.setProperty('--Blue30', Blue30);
		
        const Blue45 = Math.round(parabola(tan(45)) * Angle45/Average + UnitDistance - Heightdeviation * tan(45) + pixellength) + "px";
        document.documentElement.style.setProperty('--Blue45', Blue45);
        
        const Blue60 = Math.round(parabola(tan(30)) * Angle60/Average - Heightdeviation * tan(30) + Fullpixellength) + "px";
        document.documentElement.style.setProperty('--Blue60', Blue60);
		
        const Blue75 = Math.round(parabola(tan(15)) * Angle75/Average + UnitDistance - Heightdeviation * tan(15) - Fullpixellength - pixellength) + "px";
        document.documentElement.style.setProperty('--Blue75', Blue75);
		
        const Blue105 = Math.round(parabola(tan(15)) * Angle105/Average + UnitDistance - Heightdeviation * tan(15) - Fullpixellength - pixellength) + "px";
        document.documentElement.style.setProperty('--Blue105', Blue105);
		
        const Blue135 = Math.round(parabola(tan(45)) * Angle135/Average + UnitDistance - Heightdeviation * tan(45) + pixellength) + "px";
        document.documentElement.style.setProperty('--Blue135', Blue135);
        
        const Blue120 = Math.round(parabola(tan(30)) * Angle120/Average - Heightdeviation * tan(30) + Fullpixellength) + "px";
        document.documentElement.style.setProperty('--Blue120', Blue120);
        
        const Blue150 = Math.round(parabola(tan(30)) * Angle150/Average + UnitDistance) + "px";
        document.documentElement.style.setProperty('--Blue150', Blue150);

        const Blue165 = Math.round(parabola(tan(15)) * Angle165/Average + UnitDistance + Heightdeviation * tan(15) - Fullpixellength) + "px";
        document.documentElement.style.setProperty('--Blue165', Blue165);
		

        const NoLeftrectanglePosition15 = Math.round(NoAngle15 * Widthcoefficient + Fullpixellength / sin(15) + pixellength) + "px";
        document.documentElement.style.setProperty('--NoLeftrectanglePosition15', NoLeftrectanglePosition15);   

        const NoLeftrectanglePosition30 = Math.round(NoAngle30 * Widthcoefficient + Fullpixellength / sin(30) - pixellength) + "px";
        document.documentElement.style.setProperty('--NoLeftrectanglePosition30', NoLeftrectanglePosition30);     
		
        const NoForwardrectanglePosition45 = Math.round(NoAngle45 * Heightcoefficient + FullUnitDistance + Npixellength * square(sin(45))) + "px"; 
        document.documentElement.style.setProperty('--NoForwardrectanglePosition45', NoForwardrectanglePosition45); 
        
        const NoForwardrectanglePosition60 = Math.round(NoAngle60 * Heightcoefficient + FullUnitDistance + (Npixellength - tan(60)) * sin(60)) + "px";
        document.documentElement.style.setProperty('--NoForwardrectanglePosition60', NoForwardrectanglePosition60);
		
        const NoForwardrectanglePosition75 = Math.round(NoAngle75 * Heightcoefficient + FullUnitDistance + Npixellength * sin(75)) + "px";
        document.documentElement.style.setProperty('--NoForwardrectanglePosition75', NoForwardrectanglePosition75);
		
        const NoForwardrectanglePosition135 = Math.round(NoAngle135 * Heightcoefficient + FullUnitDistance + Npixellength * square(sin(45))) + "px";
        document.documentElement.style.setProperty('--NoForwardrectanglePosition135', NoForwardrectanglePosition135); 
        
        const NoForwardrectanglePosition = Math.round(NoAngle90 * Heightcoefficient + FullUnitDistance + Npixellength * sin(90)) + "px";
        document.documentElement.style.setProperty('--NoForwardrectanglePosition', NoForwardrectanglePosition);
		
        const NoForwardrectanglePosition105 = Math.round(NoAngle105 * Heightcoefficient + FullUnitDistance + Npixellength * sin(75)) + "px";
        document.documentElement.style.setProperty('--NoForwardrectanglePosition105', NoForwardrectanglePosition105);
        
        const NoForwardrectanglePosition120 = Math.round(NoAngle120 * Heightcoefficient + FullUnitDistance + (Npixellength - tan(60)) * sin(60)) + "px";
        document.documentElement.style.setProperty('--NoForwardrectanglePosition120', NoForwardrectanglePosition120);
        
        const NoRightrectanglePosition30 = Math.round(NoAngle150 * Widthcoefficient + Fullpixellength / sin(30) - pixellength) + "px";
        document.documentElement.style.setProperty('--NoRightrectanglePosition30', NoRightrectanglePosition30);
		
        const NoRightrectanglePosition15 = Math.round(NoAngle165 * Widthcoefficient + Fullpixellength / sin(15) + pixellength) + "px";
        document.documentElement.style.setProperty('--NoRightrectanglePosition15', NoRightrectanglePosition15);
        
		
        const NoBlue15 = Math.round(parabola(tan(15)) * NoAngle15/Average + UnitDistance + Heightdeviation * tan(15) - Fullpixellength + Npixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue15', NoBlue15);

        const NoBlue30 = Math.round(parabola(tan(30)) * NoAngle30/Average + UnitDistance + Npixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue30', NoBlue30);
		
        const NoBlue45 = Math.round(parabola(tan(45)) * NoAngle45/Average + UnitDistance - Heightdeviation * tan(45) + pixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue45', NoBlue45);
        
        const NoBlue60 = Math.round(parabola(tan(30)) * NoAngle60/Average - Heightdeviation * tan(30) + Fullpixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue60', NoBlue60);
		
        const NoBlue75 = Math.round(parabola(tan(15)) * NoAngle75/Average + UnitDistance - Heightdeviation * tan(15) - Fullpixellength - pixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue75', NoBlue75);
		
        const NoBlue105 = Math.round(parabola(tan(15)) * NoAngle105/Average + UnitDistance - Heightdeviation * tan(15) - Fullpixellength - pixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue105', NoBlue105);
		
        const NoBlue135 = Math.round(parabola(tan(45)) * NoAngle135/Average + UnitDistance - Heightdeviation * tan(45) + pixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue135', NoBlue135);
        
        const NoBlue120 = Math.round(parabola(tan(30)) * NoAngle120/Average - Heightdeviation * tan(30) + Fullpixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue120', NoBlue120);
        
        const NoBlue150 = Math.round(parabola(tan(30)) * NoAngle150/Average + UnitDistance + Npixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue150', NoBlue150);

        const NoBlue165 = Math.round(parabola(tan(15)) * NoAngle165/Average + UnitDistance + Heightdeviation * tan(15) - Fullpixellength + Npixellength) + "px";
        document.documentElement.style.setProperty('--NoBlue165', NoBlue165);


        document.documentElement.style.setProperty('--Angle0', Angle0);
        document.documentElement.style.setProperty('--Angle15', Angle15);
        document.documentElement.style.setProperty('--Angle30', Angle30);
        document.documentElement.style.setProperty('--Angle45', Angle45);
        document.documentElement.style.setProperty('--Angle60', Angle60);
        document.documentElement.style.setProperty('--Angle75', Angle75);
        document.documentElement.style.setProperty('--Angle90', Angle90);
        document.documentElement.style.setProperty('--Angle105', Angle105);
        document.documentElement.style.setProperty('--Angle120', Angle120);
        document.documentElement.style.setProperty('--Angle135', Angle135);
        document.documentElement.style.setProperty('--Angle150', Angle150);
        document.documentElement.style.setProperty('--Angle165', Angle165);
        document.documentElement.style.setProperty('--Angle180', Angle180);
        
        document.documentElement.style.setProperty('--NoAngle15', NoAngle15);
        document.documentElement.style.setProperty('--NoAngle30', NoAngle30);
        document.documentElement.style.setProperty('--NoAngle45', NoAngle45);
        document.documentElement.style.setProperty('--NoAngle60', NoAngle60);
        document.documentElement.style.setProperty('--NoAngle75', NoAngle75);
        document.documentElement.style.setProperty('--NoAngle90', NoAngle90);
        document.documentElement.style.setProperty('--NoAngle105', NoAngle105);
        document.documentElement.style.setProperty('--NoAngle120', NoAngle120);
        document.documentElement.style.setProperty('--NoAngle135', NoAngle135);
        document.documentElement.style.setProperty('--NoAngle150', NoAngle150);
        document.documentElement.style.setProperty('--NoAngle165', NoAngle165);
        
        
        document.documentElement.style.setProperty('--rgb0', rgb0);
        document.documentElement.style.setProperty('--rgb15', rgb15);
        document.documentElement.style.setProperty('--rgb30', rgb30);
        document.documentElement.style.setProperty('--rgb45', rgb45);
        document.documentElement.style.setProperty('--rgb60', rgb60);
        document.documentElement.style.setProperty('--rgb75', rgb75);
        document.documentElement.style.setProperty('--rgb90', rgb90);
        document.documentElement.style.setProperty('--rgb105', rgb105);
        document.documentElement.style.setProperty('--rgb120', rgb120);
        document.documentElement.style.setProperty('--rgb135', rgb135);
        document.documentElement.style.setProperty('--rgb150', rgb150);
        document.documentElement.style.setProperty('--rgb165', rgb165);
        document.documentElement.style.setProperty('--rgb180', rgb180);
        document.documentElement.style.setProperty('--rgb195', rgb195);
        document.documentElement.style.setProperty('--rgb210', rgb210);
        document.documentElement.style.setProperty('--rgb225', rgb225);
        document.documentElement.style.setProperty('--rgb240', rgb240);
        document.documentElement.style.setProperty('--rgb255', rgb255);
        document.documentElement.style.setProperty('--rgb270', rgb270);
        document.documentElement.style.setProperty('--rgb285', rgb285);
        document.documentElement.style.setProperty('--rgb300', rgb300);
        document.documentElement.style.setProperty('--rgb315', rgb315);
        document.documentElement.style.setProperty('--rgb330', rgb330);
        document.documentElement.style.setProperty('--rgb345', rgb345);
        
document.getElementById("pageTitle").textContent = "3D Lidar - Average: " + Average;
