SELECT  
    Activity.player_id ,MIN(Activity.event_date) AS first_login
FROM
    Activity
GROUP BY 
    player_id