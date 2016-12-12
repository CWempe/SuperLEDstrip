<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet
    version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:svg="http://www.w3.org/2000/svg"
	xmlns:xlink="http://www.w3.org/1999/xlink"
    xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape"
    >
    <xsl:output method="xml" indent="yes" encoding="UTF-8"/>
    <xsl:param name="primary_color" select="'primary_color'"/>
    <xsl:param name="secondary_color" select="'secondary_color'"/>
    <xsl:param name="primary_bright" select="'primary_bright'"/>
    <xsl:param name="secondary_bright" select="'secondary_bright'"/>
    <xsl:param name="theme" select="'theme'"/>
	
    <xsl:template match="@*|node()">
        <xsl:copy>
            <xsl:apply-templates select="@*|node()"/>
        </xsl:copy>
    </xsl:template>

	<!-- primary color -->
	<xsl:template match='svg:linearGradient[@id = "main"]/svg:stop/@stop-color'>
        <xsl:attribute name='stop-color'>
            <xsl:value-of select="$primary_color"/>
        </xsl:attribute>
    </xsl:template>
	
	<!-- secondary (accent) color -->
	<xsl:template match='svg:linearGradient[@id = "accent"]/svg:stop/@stop-color'>
        <xsl:attribute name='stop-color'>
            <xsl:value-of select="$secondary_color"/>
        </xsl:attribute>
    </xsl:template>
	
	<!-- color for tab indicator, if primary and sedondary are different, else white -->
    <xsl:template match='svg:linearGradient[@id = "tab_indicator"]/svg:stop/@stop-color'>    
		<xsl:choose>
			<xsl:when test="$primary_color!=$secondary_color">
				<xsl:attribute name='stop-color'>
					<xsl:value-of select="$secondary_color"/>
				</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='stop-color'>#FFFFFF</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	<!-- background -->
	   <xsl:template match='svg:linearGradient[@id = "background"]/svg:stop/@stop-color'>    
		<xsl:choose>
			<xsl:when test="$theme='dark'">
				<xsl:attribute name='stop-color'>#303030</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='stop-color'>#FAFAFA</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	<!-- cards, tiles -->
	<xsl:template match='svg:linearGradient[@id = "cards"]/svg:stop/@stop-color'>    
		<xsl:choose>
			<xsl:when test="$theme='dark'">
				<xsl:attribute name='stop-color'>#424242</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='stop-color'>#FFFFFF</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	
	<!-- pressed on dark buttons -->
	<xsl:template match='svg:linearGradient[@id = "pressed_dark"]/svg:stop/@stop-opacity'>    
		<xsl:choose>
			<xsl:when test="$theme='dark'">
				<xsl:attribute name='stop-opacity'>0.25</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='stop-opacity'>0.9</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	<!-- action bar shadow, top color -->
	<xsl:template match='svg:linearGradient[@id = "action_bar_shadow_colors_1"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$theme='dark'">
				<xsl:attribute name='style'>stop-color:#000000;stop-opacity:0</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#9E9E9E;stop-opacity:0</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	<!-- action bar shadow, bottom color -->
	<xsl:template match='svg:linearGradient[@id = "action_bar_shadow_colors_0"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$theme='dark'">
				<xsl:attribute name='style'>stop-color:#303030;stop-opacity:0</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#9E9E9E;stop-opacity:0</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	
	
	
	<xsl:template match='svg:linearGradient[@id = "shadow_stop_1"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$theme='dark'">
				<xsl:attribute name='style'>stop-color:#000000;stop-opacity:1</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#000000;stop-opacity:0.5</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	
	
	
	
	
	<!-- tab, icon color -->
	<xsl:template match='svg:linearGradient[@id = "tab_icon_active"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$primary_bright='dark'">
				<xsl:attribute name='style'>stop-color:#FFFFFF;stop-opacity:1</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#000000;stop-opacity:0.54</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	<!-- tile, icon color -->
	<xsl:template match='svg:linearGradient[@id = "tile_icon_active"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$theme='dark'">
				<xsl:attribute name='style'>stop-color:#FFFFFF;stop-opacity:1</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#000000;stop-opacity:0.54</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	
	
	<!-- pressed cards, tiles -->
	<xsl:template match='svg:linearGradient[@id = "cards_pressed"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$theme='dark'">
				<xsl:attribute name='style'>stop-color:#cccccc;stop-opacity:0.25</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#999999;stop-opacity:0.6</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	<!-- pressed tabs -->
	<xsl:template match='svg:linearGradient[@id = "tabs_pressed"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$primary_bright='dark'">
				<xsl:attribute name='style'>stop-color:#cccccc;stop-opacity:0.25</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#999999;stop-opacity:0.6</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	<!-- pressed floating action button -->
	<xsl:template match='svg:linearGradient[@id = "fab_pressed"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$secondary_bright='dark'">
				<xsl:attribute name='style'>stop-color:#cccccc;stop-opacity:0.25</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#999999;stop-opacity:0.6</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	<!-- floating action button, icon color -->
	<xsl:template match='svg:linearGradient[@id = "fab_button_active"]/svg:stop/@style'>    
		<xsl:choose>
			<xsl:when test="$secondary_bright='dark'">
				<xsl:attribute name='style'>stop-color:#FFFFFF;stop-opacity:1</xsl:attribute>
			</xsl:when>
			<xsl:otherwise>
				<xsl:attribute name='style'>stop-color:#000000;stop-opacity:0.54</xsl:attribute>
			</xsl:otherwise>
		</xsl:choose>
    </xsl:template>
	
	
	
	
	
</xsl:stylesheet>