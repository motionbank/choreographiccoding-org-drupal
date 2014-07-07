jQuery(function(){

	// add scroll-to anchor effect to menu and links with scroll-to-link class
    // http://css-tricks.com/snippets/jquery/smooth-scrolling/
    jQuery('a').click(function() {
        if ( location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && 
             location.hostname == this.hostname ) 
        {
            var $target = jQuery(this.hash);
            $target = $target.length ? $target : jQuery('[name=' + this.hash.slice(1) + ']');
            if ($target.length) {
                
                var t = $target.offset().top;

                jQuery('a').removeClass('active');
                jQuery(this).addClass('active');

                jQuery('html,body').animate({
                    scrollTop: t
                }, {
                    complete : function () {
                    },
                    duration: 650
                });
                return false;
            }
        }
    });



});