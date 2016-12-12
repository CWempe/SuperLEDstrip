<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet
    version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:svg="http://www.w3.org/2000/svg"
    xmlns:inkscape="http://www.inkscape.org/namespaces/inkscape"
    >
    <xsl:output method="xml" indent="yes" encoding="UTF-8"/>
    <xsl:param name="primary_color" select="'primary_color'"/>
    <xsl:param name="secondary_color" select="'secondary_color'"/>
	
    <xsl:template match="@*|node()">
        <xsl:copy>
            <xsl:apply-templates select="@*|node()"/>
        </xsl:copy>
    </xsl:template>

  <xsl:template match='svg:linearGradient[@id = "main"]/svg:stop/@stop-color'>
        <xsl:attribute name='stop-color'>
            <xsl:value-of select="$primary_color"/>
        </xsl:attribute>
    </xsl:template>
  <xsl:template match='svg:linearGradient[@id = "accent"]/svg:stop/@stop-color'>
        <xsl:attribute name='stop-color'>
            <xsl:value-of select="$secondary_color"/>
        </xsl:attribute>
    </xsl:template>
</xsl:stylesheet>