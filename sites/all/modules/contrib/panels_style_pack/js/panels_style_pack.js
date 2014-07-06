(function ($) {

/**
 * JS related to the styles in the Panels.
 */
Drupal.behaviors.panelsstyles = {
  attach: function (context) {
  	 var heightstyle = {}
  	 var collapsible = {}
  	 var expand = {}
  	 
    if(Drupal.settings.type == 'accordion') {
    var accordionID = Drupal.settings.panelsAccordion.accordionID;
    var heightstyle = { heightstyle : Drupal.settings.panelsAccordion.heightstyle }
    
    if(Drupal.settings.panelsAccordion.collapsible == 1) {
    var collapsible = {
    	collapsible: Drupal.settings.panelsAccordion.collapsible
      }
    }
    
    var optionObj = $.extend(heightstyle, collapsible);
    for (var key in Drupal.settings.panelsAccordion.accordionID) {  
      $('#' + accordionID[key] +':not(.accordion-processed)', context)
        .addClass('accordion-processed')
        .accordion(optionObj);
    }
 }
 
    if(Drupal.settings.type == 'slideshow') {
    
    function calculateTimeout(currElement, nextElement, opts, isForward) { 
    var index = opts.currSlide;
    console.log(Drupal.settings.timeoutfn[index]);
    var a = Drupal.settings.timeoutfn[index];
    return index? a : false;
    }
    
    var slideshowID = Drupal.settings.id;
    var optionObj = {
    fx: Drupal.settings.transition_type,
    easing: Drupal.settings.easing,
    sync: Drupal.settings.sync,
    timeout: Drupal.settings.timeout,
    prev: '#'+Drupal.settings.prev,
    next: '#'+Drupal.settings.next,
    pager: '#'+Drupal.settings.pager,
    timeoutFn: calculateTimeout
    }
      $('#' + slideshowID +':not(.slideshow-processed)', context)
        .addClass('slideshow-processed')
        .cycle(optionObj);
 }
 
 if(Drupal.settings.type == 'tabs') {
 	 var open_mouseover = {}
 	 var collapsible = {}
    var tabsID = Drupal.settings.panelsTabs.tabsID;
    
    if(Drupal.settings.panelsTabs.tab_style == 'open_mouseover') {
    var optionObj = { event: 'mouseover' }
    }
    else if(Drupal.settings.panelsTabs.tab_style == 'collapsible') {
    	var optionObj = { collapsible: true }
    	}

    for (var key in Drupal.settings.panelsTabs.tabsID) {  
      $('#' + tabsID[key] +':not(.tabs-processed)', context)
        .addClass('tabs-processed')
        .tabs(optionObj);
      if(Drupal.settings.panelsTabs.orientation == 'bottom') {
      	$( ".tabs-bottom .ui-tabs-nav, .tabs-bottom .ui-tabs-nav > *" )
            .removeClass( "ui-corner-all ui-corner-top" )
            .addClass( "ui-corner-bottom" );
 
        // move the nav to the bottom
        $( ".tabs-bottom .ui-tabs-nav" ).appendTo( ".tabs-bottom" );
      	}
    }
    }
    
  }
};

})(jQuery);


