const redisUrl = process.env.KV_REST_API_URL;
const redisToken = process.env.KV_REST_API_TOKEN;

async function redis(command) {
    if (!redisUrl || !redisToken) {
        throw new Error("Redis environment variables are not configured");
    }

    const response = await fetch(redisUrl, {
        method: "POST",
        headers: {
            Authorization: `Bearer ${redisToken}`,
            "Content-Type": "application/json"
        },
        body: JSON.stringify(command)
    });

    if (!response.ok) throw new Error("Redis request failed");
    return response.json();
}

module.exports = async function handler(request, response) {
    if (request.method !== "POST") {
        return response.status(405).json({ error: "Method not allowed" });
    }

    try {
        const name = typeof request.body?.name === "string" ? request.body.name.trim().slice(0, 120) : "Anonymous";
        const createdAt = new Date().toISOString();
        await redis(["INCR", "dsa:docx:count"]);
        await redis(["LPUSH", "dsa:docx:users", JSON.stringify({ name: name || "Anonymous", createdAt })]);
        await redis(["LTRIM", "dsa:docx:users", "0", "499"]);
        return response.status(204).end();
    } catch (error) {
        console.error(error);
        return response.status(503).json({ error: "Analytics storage unavailable" });
    }
};